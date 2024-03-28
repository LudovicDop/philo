/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:17:06 by ludovicdopp       #+#    #+#             */
/*   Updated: 2024/03/28 12:10:32 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_my_args(char **argv, int argc)
{
	int	i;
	int	j;

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
	return (0);
}

void	init_fork(t_tab **tab, t_philo **philo, t_rules **rules, char **argv)
{
	int			i;
	long long	time;

	time = get_current_time();
	i = 0;
	while (i < (*tab)->fork)
	{
		pthread_mutex_init(&(*philo)[i].fork, NULL);
		(*philo)[i].last_eat = time;
		(*tab)->first_fork = &(*philo)[0].fork;
		i++;
	}
}

int	start_philo_bis(t_tab **tab, t_philo **philo)
{
	int	i;

	i = 0;
	while (i < (*tab)->fork)
	{
		if (pthread_create(&(*philo)[i].th, NULL, (void *)philosophers,
			&(*philo)[i]) != 0)
			return (2);
		i++;
	}
	i = 0;
	while (i < (*tab)->fork)
	{
		if (pthread_join((*philo)[i].th, NULL) != 0)
			return (2);
		i++;
	}
	return (0);
}

int	start_philo(t_tab **tab, t_philo **philo, t_rules **rules, char **argv)
{
	int	i;

	i = 0;
	while (i < (*tab)->fork)
	{
		(*philo)[i].id = i + 1;
		(*philo)[i].rules = *rules;
		(*philo)[i].tab = *tab;
		i++;
	}
	init_fork(tab, philo, rules, argv);
	start_philo_bis(tab, philo);
	ft_end(*philo);
	return (0);
}

int	main(int argc, char **argv)
{
	t_tab	*tab;
	t_philo	*philo;
	t_rules	*rules;

	if (check_my_args(argv + 1, argc))
	{
		printf("Please enter some valid parameter!\n");
		return (2);
	}
	if (argc == 6 || argc == 5)
	{
		if (init_philo(&tab, &philo, &rules, argv))
			return (1);
		tab->argc = argc;
	}
	else
	{
		printf("Look like there is not enough arguments!\n");
		return (1);
	}
	start_philo(&tab, &philo, &rules, argv);
	return (0);
}
