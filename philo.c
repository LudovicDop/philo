/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:47:22 by ldoppler          #+#    #+#             */
/*   Updated: 2024/03/13 15:43:13 by ldoppler         ###   ########.fr       */
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
    pthread_mutex_lock(&(tmp)->tab->mutex);
    usleep(tmp->rules->time_to_eat * 1000);
    printf("%lld %d is eating\n", get_time(tmp->tab->global_time), (tmp)->id);
    //tmp->fork = false;
    pthread_mutex_unlock(&tmp->tab->mutex);
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
    printf("id testt : %d!\n", tmp[1].id);
    take_a_fork(tmp);
    i_m_eating(tmp);
    i_m_sleeping(tmp);
    i_m_thinking_about_my_fucking_life(tmp);
    return (NULL);
}
