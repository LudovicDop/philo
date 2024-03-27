/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:52:50 by ldoppler          #+#    #+#             */
/*   Updated: 2024/03/27 12:43:15 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void    check_die(t_philo *philo)
{
    long long last_time_eat;

    last_time_eat = get_current_time() - philo->last_time_eat; 
    //printf("%lld | %d \n", last_time_eat, philo->rules->time_before_die);
    if (last_time_eat >= philo->rules->time_before_die)
    {
        printf("%ld %d died\n", get_current_time() - philo->rules->start_time, philo->id);
        exit(EXIT_FAILURE);
    }
}
void    is_eating(t_philo *philo)
{
    sem_wait(&philo->rules->fork);
    printf("%ld %d has taken a fork\n", get_current_time() - philo->rules->start_time, philo->id);
    printf("%ld %d has taken a fork\n", get_current_time() - philo->rules->start_time, philo->id);
    check_die(philo);
    printf("%ld %d is eating\n", get_current_time() - philo->rules->start_time, philo->id);
    philo->last_time_eat = get_current_time();
    check_die(philo);
    ft_usleep(philo->rules->time_to_eat);
    sem_post(&philo->rules->fork);
    return ;
}
void    is_sleeping(t_philo *philo)
{
    printf("%ld %d is sleeping\n", get_current_time() - philo->rules->start_time, philo->id);
    check_die(philo);
    ft_usleep(philo->rules->time_to_sleep);
    check_die(philo);
}

void    is_thinking(t_philo *philo)
{
    printf("%ld %d is thinking\n", get_current_time() - philo->rules->start_time, philo->id);
}

void    *philosophers(void *arg)
{
    t_philo *philo;

    philo = arg;
    is_eating(philo);
    is_sleeping(philo);
    is_thinking(philo);
    return (NULL);
}
