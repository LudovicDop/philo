/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:47:22 by ldoppler          #+#    #+#             */
/*   Updated: 2024/03/11 17:53:50 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    i_m_eating(t_philo *tmp)
{
   
    pthread_mutex_lock(&(tmp)->tab->mutex);
    printf("time_to_eat : %d\n", tmp->rules->time_to_eat);
     sleep(2);
    usleep(tmp->rules->time_to_eat);
    pthread_mutex_unlock(&tmp->tab->mutex);
}

void    i_m_sleeping(t_philo *tmp)
{

}

void    i_m_thinking_about_my_fucking_life(t_philo *tmp)
{
    
}

void	*philosophers(void *arg)
{
	t_philo	*tmp;

	tmp = (t_philo *)arg;
	printf("Hello %d\n", tmp->id);
    i_m_eating(tmp);
}
