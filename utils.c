/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:31:12 by ldoppler          #+#    #+#             */
/*   Updated: 2024/03/28 15:04:46 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_max(char **argv, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		if (ft_atoi(argv[i]) == -1)
			return (2);
		i++;
	}
	return (0);
}

long long	get_time(long long startTime)
{
	return (get_current_time() - startTime);
}

int	ft_usleep(long long milliseconds)
{
	long long	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
	{
		usleep(500);
	}
	return (0);
}

int	ft_printf(char *str, long long milisec, t_philo *tmp, long long sleep)
{
	if (check_die(tmp))
		return (1);
	if (get_current_time() - tmp->last_eat + sleep < tmp->rules->time_to_die)
	{
		printf("%lld %d %s\n", milisec, tmp->id, str);
		ft_usleep(sleep);
	}
	else
	{
		pthread_mutex_lock(&tmp->rules->die);
		tmp->rules->someone_die = 1;
		ft_usleep(tmp->rules->time_to_die);
		printf("%lld %d %s\n", milisec, tmp->id, str);
		printf("%lld %d died\n", get_time(tmp->tab->global), tmp->id);
		pthread_mutex_unlock(&tmp->rules->die);
		return (1);
	}
	if (check_die(tmp) && !tmp->rules->someone_die)
		return (1);
	return (0);
}

int	check_die(t_philo *arg)
{
	t_philo		*philo;
	long long	last_eat;

	philo = arg;
	last_eat = get_current_time() - philo->last_eat;
	if (arg->rules->someone_die)
		return (1);
	pthread_mutex_lock(&philo->rules->die);
	if (last_eat >= arg->rules->time_to_die && !arg->rules->someone_die)
	{
		philo->rules->someone_die = 1;
		printf("%lld %d died\n", get_time(philo->tab->global), arg->id);
		pthread_mutex_unlock(&philo->rules->die);
		return (1);
	}
	pthread_mutex_unlock(&philo->rules->die);
	return (0);
}
