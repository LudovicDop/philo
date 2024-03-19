/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:47:22 by ldoppler          #+#    #+#             */
/*   Updated: 2024/03/19 11:11:07 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void check_die(t_philo *tmp)
{
    t_philo *philo;
    long long calc;

    philo = tmp;
    calc = getCurrentTimeMillis() - philo->last_eat;

    printf("here : %lld %lld\n", calc, philo->rules->time_to_eat);
    if (calc > philo->rules->time_to_eat)
    {
        tmp->rules->someone_die = 1;
        printf("%lld %d die\n", get_time(philo->tab->global_time), philo->id);
        exit(EXIT_FAILURE);
    }
}

void    i_m_eating(t_philo *tmp)
{
    long long   time;

    pthread_mutex_lock(&tmp->fork);
    check_die(tmp);
    printf("%lld %d has taken a fork\n", get_time(tmp->tab->global_time), (tmp)->id);
    if (tmp->id != tmp->tab->fork)
    {
        pthread_mutex_lock(&(tmp + 1)->fork);
        check_die(tmp);
        printf("%lld %d has taken a fork\n", get_time(tmp->tab->global_time), (tmp)->id);
    }
    else
    {
        pthread_mutex_lock(tmp->tab->first_fork);
        check_die(tmp);
        printf("%lld %d has taken a fork\n", get_time(tmp->tab->global_time), (tmp)->id);
    }
    time = get_time(tmp->tab->global_time);
    check_die(tmp);
    printf("%lld %d is eating\n", time, (tmp)->id);
    usleep(tmp->rules->time_to_eat * 1000);
    tmp->last_eat = getCurrentTimeMillis();
    pthread_mutex_unlock(&tmp->fork);
    if (tmp->id != tmp->tab->fork)
        pthread_mutex_unlock(&(tmp + 1)->fork);
    else
        pthread_mutex_unlock(tmp->tab->first_fork);
}

void    i_m_sleeping(t_philo *tmp)
{
    check_die(tmp);
    printf("%lld %d is sleeping\n", get_time(tmp->tab->global_time), (tmp)->id);
    usleep(tmp->rules->time_to_sleep * 1000);
}

void    i_m_thinking_about_my_fucking_life(t_philo *tmp)
{
     check_die(tmp);
     printf("%lld %d is thinking\n", get_time(tmp->tab->global_time), (tmp)->id);
}

void	*philosophers(void *arg)
{
	t_philo *tmp;

	tmp = (t_philo *)arg;
    if ((tmp->id % 2 == 0) || tmp->id == tmp->tab->fork)
	{
        usleep(100);
    }
    i_m_eating(tmp);
    i_m_sleeping(tmp);
    i_m_thinking_about_my_fucking_life(tmp);
    return (NULL);
}
