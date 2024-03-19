/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:47:22 by ldoppler          #+#    #+#             */
/*   Updated: 2024/03/19 17:00:40 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    check_die(t_philo *arg)
{
    t_philo *philo;
    long long   last_eat;
    
    philo = arg;
    last_eat =  getCurrentTimeMillis() - philo->last_eat;
    //printf("%lld > %lld\n", last_eat, arg->rules->time_to_die);
    if (arg->rules->someone_die)
        exit(EXIT_FAILURE);
    if (last_eat >= arg->rules->time_to_die)
    {
        philo->rules->someone_die = 1;
        printf("%lld %d died\n",get_time(philo->tab->global_time), arg->id);
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
    check_die(tmp);
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
     //usleep(tmp->rules->time_to_eat);
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
