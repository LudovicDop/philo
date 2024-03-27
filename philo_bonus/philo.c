/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:52:50 by ldoppler          #+#    #+#             */
/*   Updated: 2024/03/27 13:04:26 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int    check_die(t_philo *philo)
{
    long long last_time_eat;

    last_time_eat = get_current_time() - philo->last_time_eat; 
    if (philo->rules->someone_die)
        return (2);
    if (last_time_eat >= philo->rules->time_before_die && philo->rules->someone_die != 1)
    {
        philo->rules->someone_die = 1;
        printf("%ld %d died\n", get_current_time() - philo->rules->start_time, philo->id);
        exit(EXIT_FAILURE);
    }
    return (0);
}
int    ft_printf(t_philo *philo, char *string, long long sleep)
{
    int ret;

    ret = 0;
    ret += check_die(philo);
    printf("%ld %d %s\n", get_current_time() - philo->rules->start_time, philo->id, string);
    ft_usleep(sleep);
    ret += check_die(philo);
    return (ret);
}
int    is_eating(t_philo *philo)
{
    int ret;

    ret = 0;
    sem_wait(&philo->rules->fork);
    ft_printf(philo, "has taken a fork", 0);
    ft_printf(philo, "has taken a fork", 0);
    ret = ft_printf(philo, "is eating", philo->rules->time_to_eat);
    philo->last_time_eat = get_current_time();
    sem_post(&philo->rules->fork);
    return (ret);
}
int    is_sleeping(t_philo *philo)
{
    int ret;
    
    ret = 0;
    ret = ft_printf(philo, "is sleeping", philo->rules->time_before_die);
    return (ret);
}

int    is_thinking(t_philo *philo)
{
    int ret;

    ret = 0;
    ret = ft_printf(philo, "is thinking", 0);
    return (ret);
}

int    *philosophers(void *arg)
{
    t_philo *philo;

    philo = arg;
    if (is_eating(philo))
        return (2);
    if (is_sleeping(philo))
        return (2);
    if (is_thinking(philo))
        return (2);
    return (NULL);
}
