/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:47:22 by ldoppler          #+#    #+#             */
/*   Updated: 2024/03/12 14:02:49 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    i_m_eating(t_philo *tmp)
{
   
    pthread_mutex_lock(&(tmp)->tab->mutex);
    //sleep(1);
    printf("%lld %d is eating\n", get_time(tmp->tab->global_time), (tmp)->id);
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
    i_m_eating(tmp);
    return (NULL);
}
