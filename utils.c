/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:31:12 by ldoppler          #+#    #+#             */
/*   Updated: 2024/03/21 13:42:23 by ldoppler         ###   ########.fr       */
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
	int	ret;
	int	i;
	int	is_neg;

	is_neg = 1;
	i = 0;
	ret = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			is_neg = is_neg * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = (ret * 10) + str[i] - '0';
		i++;
	}
	return (ret * is_neg);
}

long int getCurrentTimeMillis() {
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);

    return (currentTime.tv_sec * 1000 + currentTime.tv_usec / 1000);
}

long long get_time(long long startTime) {
    return getCurrentTimeMillis() - startTime;
}

int	ft_usleep(long long milliseconds)
{
	long long	start;

	start = getCurrentTimeMillis();
	while ((getCurrentTimeMillis() - start) < milliseconds)
	{
		//printf("%ld %lld = %lld | %lld\n", getCurrentTimeMillis(), start,(getCurrentTimeMillis() - start), milliseconds);
		usleep(500);
	}
	return (0);
}




