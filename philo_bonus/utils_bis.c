/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:59:33 by ldoppler          #+#    #+#             */
/*   Updated: 2024/03/28 12:30:12 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_die(t_philo *philo)
{
	long long	last_time_eat;

	last_time_eat = get_current_time() - philo->last_time_eat;
	if (philo->rules->someone_die)
		return (2);
	sem_wait(&philo->rules->die);
	if (last_time_eat >= philo->rules->time_before_die
		&& philo->rules->someone_die != 1)
	{
		printf("%lld %d\n", last_time_eat, philo->rules->time_before_die);
		philo->rules->someone_die = 1;
		printf("%ld %d died\n", get_current_time() - philo->rules->start_time,
			philo->id);
		sem_post(&philo->rules->die);
		return (2);
	}
	sem_post(&philo->rules->die);
	return (0);
}
