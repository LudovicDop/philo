/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovicdoppler <ludovicdoppler@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:17:06 by ludovicdopp       #+#    #+#             */
/*   Updated: 2024/03/16 16:00:36 by ludovicdopp      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_fork(t_tab **tab, t_philo **philo, t_rules **rules, char **argv)
{
	int	i;

	i = 0;
	while (i < (*tab)->fork)
	{
		pthread_mutex_init(&(*philo)[i].fork, NULL);
		(*tab)->first_fork = &(*philo)[0].fork;
		// if (((*philo)[i].id % 2 == 0) || (*philo)[i].id == (*tab)->fork)
		// {
		// 	pthread_mutex_lock(&(*philo)[i].fork);
		// 	printf("ID Philo : %d\n", (*philo)[i].id);
		// }
		i++;
	}
}

void	start_philo(t_tab **tab, t_philo **philo, t_rules **rules, char **argv)
{
	int	i;
	int	repeat;

	repeat = ft_atoi(argv[5]);
	i = 0;

	while (i < (*tab)->fork)
	{
		(*philo)[i].id = i + 1;
        (*philo)[i].rules = *rules;
        (*philo)[i].tab = *tab;
		i++;
	}
	init_fork(tab, philo, rules, argv);
	i = 0;
	while (i < (*tab)->fork)
	{
		// pthread_create(&(*philo)[i].th, NULL, (void *)philosophers,
		// 	&(*philo)[i]);
		if (((*philo)[i].id % 2 == 0) || (*philo)[i].id == (*tab)->fork)
		{
			pthread_create(&(*philo)[i].th, NULL, (void *)philosophers,
		 	&(*philo)[i]);
			//printf("ID Philo : %d\n", (*philo)[i].id);
		}
		i++;
	}
	i = 0;
	while (i < (*tab)->fork)
	{
		// pthread_create(&(*philo)[i].th, NULL, (void *)philosophers,
		// 	&(*philo)[i]);
		if (!((*philo)[i].id % 2 == 0) && (*philo)[i].id != (*tab)->fork)
		{
			pthread_create(&(*philo)[i].th, NULL, (void *)philosophers,
		 	&(*philo)[i]);
			//printf("ID Philo : %d\n", (*philo)[i].id);
		}
		i++;
	}
	i = 0;
	while (i < (*tab)->fork)
	{
		pthread_join((*philo)[i].th, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_tab		*tab;
	t_philo		*philo;
	t_rules		*rules;
	long long	startTime;
	long long	endTime;

	//startTime = getCurrentTimeMillis();
	if (argc == 6)
	{
		if (init_philo(&tab, &philo, &rules, argv))
			return (1);
	}
	else
	{
		printf("Look like there is not enough arguments!\n");
		return (1);
	}
    start_philo(&tab, &philo, &rules, argv);
	free(tab);
	//endTime = getCurrentTimeMillis() - startTime;
	//printf("default time : %lld\n", endTime);
	return (0);
}
