/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:17:06 by ludovicdopp       #+#    #+#             */
/*   Updated: 2024/03/12 14:12:00 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_philo(t_tab **tab, t_philo **philo, t_rules **rules, char **argv)
{
	int	i;

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
