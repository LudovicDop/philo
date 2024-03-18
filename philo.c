/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovicdoppler <ludovicdoppler@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:47:22 by ldoppler          #+#    #+#             */
/*   Updated: 2024/03/18 11:55:54 by ludovicdopp      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void check_die(t_philo *tmp)
{
    long long   time;

    time = get_time(tmp->tab->global_time);
    printf("%lld - %lld = %lld\n", time , tmp->last_eat, (time - tmp->last_eat));
    if ((time - tmp->last_eat) > tmp->rules->time_to_die)
    {
        printf("You die bitch %d\n", tmp->id);
        exit(EXIT_FAILURE);
    }
}

void    i_m_eating(t_philo *tmp)
{
    long long   time;

    pthread_mutex_lock(&tmp->fork);
    printf("%lld %d has taken a fork\n", get_time(tmp->tab->global_time), (tmp)->id);
    if (tmp->id != tmp->tab->fork)
    {
        pthread_mutex_lock(&(tmp + 1)->fork);
        printf("%lld %d has taken a fork\n", get_time(tmp->tab->global_time), (tmp)->id);
    }
    else
    {
        pthread_mutex_lock(tmp->tab->first_fork);
        printf("%lld %d has taken a fork\n", get_time(tmp->tab->global_time), (tmp)->id);
    }
    time = get_time(tmp->tab->global_time);
    printf("%lld %d is eating\n", time, (tmp)->id);
    usleep(tmp->rules->time_to_eat * 1000);
    pthread_mutex_unlock(&tmp->fork);
    if (tmp->id != tmp->tab->fork)
        pthread_mutex_unlock(&(tmp + 1)->fork);
    else
        pthread_mutex_unlock(tmp->tab->first_fork);
}

void    i_m_sleeping(t_philo *tmp)
{
    printf("%lld %d is sleeping\n", get_time(tmp->tab->global_time), (tmp)->id);
    usleep(tmp->rules->time_to_sleep * 1000);
}

void    i_m_thinking_about_my_fucking_life(t_philo *tmp)
{
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
