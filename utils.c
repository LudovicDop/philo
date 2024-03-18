/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovicdoppler <ludovicdoppler@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:31:12 by ldoppler          #+#    #+#             */
/*   Updated: 2024/03/18 11:41:41 by ludovicdopp      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

long long getCurrentTimeMillis() {
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);

    return (currentTime.tv_sec * 1000LL + currentTime.tv_usec / 1000LL);
}

long long get_time(long long startTime) {
    return getCurrentTimeMillis() - startTime;
}

// void	ft_usleep(t_philo *arg)
// {
// 	long long time;

// 	time = getCurrentTimeMillis();
// 	while (!arg->rules->someone_die)
// 	{

// 	}
// }



