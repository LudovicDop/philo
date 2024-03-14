/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:31:12 by ldoppler          #+#    #+#             */
/*   Updated: 2024/03/14 16:47:05 by ldoppler         ###   ########.fr       */
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

// long long getCurrentTimeMillis() {
//     struct timeval currentTime;
//     gettimeofday(&currentTime, NULL);

//     return (currentTime.tv_sec * 1000 + currentTime.tv_usec / 1000);
// }

// long long get_time(long long start_time)
// {
// 	long long ret;

// 	ret = getCurrentTimeMillis() - start_time;
// 	return (ret);
// }

#include <sys/time.h>

long long getCurrentTimeMillis() {
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);

    return (currentTime.tv_sec * 1000LL + currentTime.tv_usec / 1000LL);
}

long long get_time(long long startTime) {
    return getCurrentTimeMillis() - startTime;
}



