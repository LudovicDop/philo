/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovicdoppler <ludovicdoppler@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:47:22 by ldoppler          #+#    #+#             */
/*   Updated: 2024/03/16 16:25:11 by ludovicdopp      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    take_a_fork(t_philo *tmp)
{
   // pthread_mutex_lock(&tmp->fork);
    printf("%lld %d has taken a fork\n", get_time(tmp->tab->global_time), (tmp)->id);
}

void    check_die(t_philo *tmp)
{
    printf("%lld %d died\n", get_time(tmp->tab->global_time), (tmp)->id);
}
void    i_m_eating(t_philo *tmp)
{
    long long test;

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
    usleep(tmp->rules->time_to_eat * 1000);
    test = get_time(tmp->tab->global_time);
    printf("%lld %d is eating\n", test, (tmp)->id);
    pthread_mutex_unlock(&tmp->fork);
    if (tmp->id != tmp->tab->fork)
        pthread_mutex_unlock(&(tmp + 1)->fork);
    else
        pthread_mutex_unlock(tmp->tab->first_fork);
}

void    i_m_sleeping(t_philo *tmp)
{
    usleep(tmp->rules->time_to_sleep * 1000);
    printf("%lld %d is sleeping\n", get_time(tmp->tab->global_time), (tmp)->id);
}

void    i_m_thinking_about_my_fucking_life(t_philo *tmp)
{
     printf("%lld %d is thinking\n", get_time(tmp->tab->global_time), (tmp)->id);
}

void	*philosophers(void *arg)
{
	t_philo	*tmp;

	tmp = (t_philo *)arg;
    // if (tmp->id != tmp->tab->fork)
    //     printf("id testt : %d (%p)&& %d!)\n", tmp->id, &tmp->fork, (tmp + 1)->id);
    // else
    // {
    //     printf("ICI id testt : %d && %p!\n", tmp->id, tmp->tab->first_fork);
    // }
    //take_a_fork(tmp);
    i_m_eating(tmp);
    i_m_sleeping(tmp);
    i_m_thinking_about_my_fucking_life(tmp);
    return (NULL);
}
