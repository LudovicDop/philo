/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:41:20 by ldoppler          #+#    #+#             */
/*   Updated: 2024/03/28 14:54:26 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_my_args(char **argv, int argc)
{
	int	i;
	int	j;
	long long value;

	value = 0;
	j = 0;
	i = 0;
	while (i < argc - 1)
	{
		while (argv[i])
		{
			j = 0;
			while (argv[i][j] >= '0' && argv[i][j] <= '9')
			{
				j++;
			}
			if (argv[i][j] != '\0')
				return (2);
			i++;
		}
	}
	if (ft_atoi(argv[0]) <= 0)
		return (2);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	ret;
	int	i;
	int	is_neg;

	is_neg = 1;
	i = 0;
	ret = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ' && i < 31)
		i++;
	if (str[i] == '+' || str[i] == '-')
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
	return (ret * is_neg);
}

long int	get_current_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

int	ft_usleep(long long milliseconds, t_philo *philo)
{
	long long	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
	{
		usleep(500);
	}
	return (0);
}
