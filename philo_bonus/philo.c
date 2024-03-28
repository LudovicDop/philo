/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:52:50 by ldoppler          #+#    #+#             */
/*   Updated: 2024/03/28 15:24:16 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_printf(t_philo *philo, char *string, long long sleep)
{
	int	ret;

	ret = 0;
	if (check_die(philo))
		return (2);
	if (get_current_time() - philo->last_time_eat
		+ sleep < philo->rules->time_before_die)
	{
		printf("%ld %d %s\n", get_current_time() - philo->rules->start_time,
			philo->id, string);
		ft_usleep(sleep, philo);
	}
	else
	{
		sem_wait(&philo->rules->die);
		philo->rules->someone_die = 1;
		printf("%ld %d %s\n", get_current_time() - philo->rules->start_time,
			philo->id, string);
		ft_usleep(philo->rules->time_before_die, philo);
		printf("%ld %d died\n", get_current_time() - philo->rules->start_time,
			philo->id);
		sem_post(&philo->rules->die);
		return (1);
	}
	return (check_die(philo));
}

int	is_eating(t_philo *philo)
{
	int	ret;

	ret = 0;
	sem_wait(&philo->rules->fork);
	ret += ft_printf(philo, "has taken a fork", 0);
	ret += ft_printf(philo, "has taken a fork", 0);
	ret += ft_printf(philo, "is eating", philo->rules->time_to_eat);
	philo->last_time_eat = get_current_time();
	sem_post(&philo->rules->fork);
	return (ret);
}

int	is_sleeping(t_philo *philo)
{
	return (ft_printf(philo, "is sleeping", philo->rules->time_to_sleep));
}

int	is_thinking(t_philo *philo)
{
	return (ft_printf(philo, "is thinking", 0));
}

int	philosophers(void *arg)
{
	t_philo	*philo;
	int		j;
	int		neg;

	neg = -1;
	j = 0;
	philo = arg;
	if (only_one(philo))
		return (2);
	while (j < philo->rules->how_many_dinner
		|| philo->rules->how_many_dinner == neg)
	{
		if (philo->id > philo->rules->nbre_of_philo / 2)
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
