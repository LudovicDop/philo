/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:17:06 by ludovicdopp       #+#    #+#             */
/*   Updated: 2024/03/14 16:29:32 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_fork(t_tab **tab, t_philo **philo, t_rules **rules, char **argv)
{
	int	i;

	i = 0;
	printf("Begin init_fork!\n");
	while (i < (*tab)->fork)
	{
		if (((*philo)[i].id % 2 == 0) || (*philo)[i].id == (*tab)->fork)
		{
			// pthread_mutex_init(&(*philo)[i].fork, NULL);
			// pthread_mutex_lock(&(*philo)[i].fork);
			printf("ID Philo : %d\n", (*philo)[i].id);
		}
		i++;
	}
	// pthread_mutex_init(&(*philo)[i].fork, NULL);
	// pthread_mutex_init(&(*philo)[1].fork, NULL);
	// pthread_mutex_lock(&(*philo)[i].fork);
    // pthread_mutex_lock(&(*philo)[1].fork);
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
		pthread_create(&(*philo)[i].th, NULL, (void *)philosophers,
			&(*philo)[i]);
		i++;
	}
	init_fork(tab, philo, rules, argv);
	i = 0;
	while (i < (*tab)->fork)
	{
		pthread_join((*philo)[i].th, NULL);
		i++;
	}
	//printf("test id : %d\n", (*philo)[3].id);
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
