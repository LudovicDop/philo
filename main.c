/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:17:06 by ludovicdopp       #+#    #+#             */
/*   Updated: 2024/03/21 13:43:14 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_fork(t_tab **tab, t_philo **philo, t_rules **rules, char **argv)
{
	int	i;
	long long	time;

	time = getCurrentTimeMillis();
	i = 0;
	while (i < (*tab)->fork)
	{
		pthread_mutex_init(&(*philo)[i].fork, NULL);
		(*philo)[i].last_eat = time;
		(*tab)->first_fork = &(*philo)[0].fork;
		i++;
	}
}

void	start_philo(t_tab **tab, t_philo **philo, t_rules **rules, char **argv)
{
	int	i;
	int j;
	int	repeat;

	j = 0;
	repeat = ft_atoi(argv[5]);
	while (j < repeat)
	{
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
			pthread_create(&(*philo)[i].th, NULL, (void *)philosophers,
			&(*philo)[i]);
			i++;
		}
		i = 0;
		while (i < (*tab)->fork)
		{
			pthread_join((*philo)[i].th, NULL);
			i++;
		}
		j++;
	}
	ft_end(*philo);
}

int	main(int argc, char **argv)
{
	t_tab		*tab;
	t_philo		*philo;
	t_rules		*rules;

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
	return (0);
}
