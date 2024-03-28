/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:52:50 by ldoppler          #+#    #+#             */
/*   Updated: 2024/03/28 12:04:02 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int    check_die(t_philo *philo)
{
    long long last_time_eat;

    last_time_eat = get_current_time() - philo->last_time_eat; 
    if (philo->rules->someone_die)
        return (2);
    sem_wait(&philo->rules->die);
    if (last_time_eat >= philo->rules->time_before_die && philo->rules->someone_die != 1)
    {
        printf("%lld %d\n", last_time_eat, philo->rules->time_before_die);
        philo->rules->someone_die = 1;
        printf("%ld %d died\n", get_current_time() - philo->rules->start_time, philo->id);
        sem_post(&philo->rules->die);
        return (2);
    }
    sem_post(&philo->rules->die);
    return (0);
}
int    ft_printf(t_philo *philo, char *string, long long sleep)
{
    int ret;

    ret = 0;
    if (check_die(philo))
        return (2);
    printf("%ld %d %s\n", get_current_time() - philo->rules->start_time, philo->id, string);
    ft_usleep(sleep, philo);
    if (check_die(philo))
        return (2);
    return (ret);
}
int    is_eating(t_philo *philo)
{
    int ret;

    ret = 0;
    sem_wait(&philo->rules->fork);
    ret += ft_printf(philo, "has taken a fork", 0);
    ret += ft_printf(philo, "has taken a fork", 0);
    ret += ft_printf(philo, "is eating", philo->rules->time_to_eat);
    philo->last_time_eat = get_current_time();
    sem_post(&philo->rules->fork);
    return (ret);
}
int    is_sleeping(t_philo *philo)
{
    return (ft_printf(philo, "is sleeping", philo->rules->time_to_sleep));
}

int    is_thinking(t_philo *philo)
{
    return (ft_printf(philo, "is thinking", 0));
}

int    philosophers(void *arg)
{
    t_philo *philo;
    int     j;

    j = 0;
    philo = arg;
    while (j < philo->rules->how_many_dinner || philo->rules->how_many_dinner == -1)
    {
        if (philo->id >  philo->rules->nbre_of_philo / 2)
            usleep(500);
        if (is_eating(philo))
            return (2);
        if (is_sleeping(philo))
            return (2);
        if (is_thinking(philo))
            return (2);
        j++;
    }
    return (0);
}
