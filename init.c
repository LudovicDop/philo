/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovicdoppler <ludovicdoppler@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:45:32 by ldoppler          #+#    #+#             */
/*   Updated: 2024/03/16 18:18:37 by ludovicdopp      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	malloc_struct(t_tab **tab, t_philo **philo, t_rules **rules, char **argv)
{
	*tab = malloc(sizeof(t_tab));
	if (!(*tab))
		return (2);
	(*tab)->fork = ft_atoi(argv[1]);
	if ((*tab)->fork < 1)
	{
		printf("Not enought philosophers!\n");
		return (free(*tab), 1);
	}
	*philo = malloc(sizeof(t_philo) * (*tab)->fork);
	if (!(*philo))
		return (2);
	*rules = malloc(sizeof(t_rules));
	if (!(*rules))
		return (2);
	return (0);
}

int	init_philo(t_tab **tab, t_philo **philo, t_rules **rules, char **argv)
{
	if (malloc_struct(tab, philo, rules, argv))
		return (2);
    (*rules)->nbre_philo = (*tab)->fork;
    (*rules)->time_to_die = ft_atoi(argv[2]);
    (*rules)->time_to_eat = ft_atoi(argv[3]);
    (*rules)->time_to_sleep = ft_atoi(argv[4]);
	(*tab)->global_time = getCurrentTimeMillis();
	return (0);
}
