/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:52:50 by ldoppler          #+#    #+#             */
/*   Updated: 2024/03/27 12:13:53 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void    is_eating(t_philo *philo)
{
    sem_wait(&philo->rules->fork);
    printf("%ld %d has taken a fork\n", get_current_time() - philo->rules->start_time, philo->id);
    sem_wait(&philo->rules->fork);
    printf("%ld %d has taken a fork\n", get_current_time() - philo->rules->start_time, philo->id);
    printf("%ld %d is eating\n", get_current_time() - philo->rules->start_time, philo->id);
    ft_usleep(philo->rules->time_to_eat);
    sem_post(&philo->rules->fork);
    sem_post(&philo->rules->fork);
    return ;
}

void    *philosophers(void *arg)
{
    t_philo *philo;

    philo = arg;
    is_eating(philo);
    // sem_wait(&philo->rules->fork);
    // sleep(1);
    // printf("hello %d\n", philo->id);
    // sem_post(&philo->rules->fork);
    return (NULL);
}
