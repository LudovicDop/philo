/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:54:26 by ldoppler          #+#    #+#             */
/*   Updated: 2024/03/28 15:07:30 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_everything(t_philo *tmp)
{
	t_philo	*philo;

	philo = tmp;
	free(philo->tab);
	philo->tab = NULL;
	free(philo->rules);
	philo->rules = NULL;
	free(philo);
	philo = NULL;
}

void	kill_mutex(t_philo *tmp)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = tmp;
	while (i < tmp->tab->fork)
	{
		pthread_mutex_destroy(&tmp[i].fork);
		i++;
	}
}

void	ft_end(t_philo *tmp)
{
	kill_mutex(tmp);
	free_everything(tmp);
}

int	ft_atoi(const char *str)
{
	long long	ret;
	int			i;
	int			is_neg;

	is_neg = 1;
	i = 0;
	ret = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == ' ') && i < 31)
		i++;
	if (str[i] == '+' || str[i] == '-' && i < 31)
	{
		if (str[i] == '-')
			is_neg = is_neg * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && i < 31)
	{
		ret = (ret * 10) + str[i] - '0';
		i++;
	}
	if (ret >= INT_MAX || i >= 31)
		return (-1);
	return ((int)ret * is_neg);
}

long int	get_current_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}
