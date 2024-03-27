/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:52:50 by ldoppler          #+#    #+#             */
/*   Updated: 2024/03/27 12:54:57 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void    check_die(t_philo *philo)
{
    long long last_time_eat;

    last_time_eat = get_current_time() - philo->last_time_eat; 
    //printf("%lld | %d \n", last_time_eat, philo->rules->time_before_die);
    if (last_time_eat >= philo->rules->time_before_die && philo->rules->someone_die != 1)
    {
        philo->rules->someone_die = 1;
        printf("%ld %d died\n", get_current_time() - philo->rules->start_time, philo->id);
        exit(EXIT_FAILURE);
    }
}
void    ft_printf(t_philo *philo, char *string, long long sleep)
{
    check_die(philo);
    printf("%ld %d %s\n", get_current_time() - philo->rules->start_time, philo->id, string);
    ft_usleep(sleep);
    check_die(philo);
}
void    is_eating(t_philo *philo)
{
    sem_wait(&philo->rules->fork);
    ft_printf(philo, "has taken a fork", 0);
    ft_printf(philo, "has taken a fork", 0);
    ft_printf(philo, "is eating", philo->rules->time_to_eat);
    philo->last_time_eat = get_current_time();
    sem_post(&philo->rules->fork);
    return ;
}
void    is_sleeping(t_philo *philo)
{
    ft_printf(philo, "is sleeping", philo->rules->time_before_die);
}

void    is_thinking(t_philo *philo)
{
    ft_printf(philo, "is thinking", 0);
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