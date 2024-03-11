/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:17:06 by ludovicdopp       #+#    #+#             */
/*   Updated: 2024/03/11 14:57:52 by ldoppler         ###   ########.fr       */
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

void    *f1(void)
{
    printf("Hello\n");
}
int	init_philo(t_tab **tab, t_philo **philo, t_rules **rules, char **argv)
{
    int i;

    i = 0;
	if (malloc_struct(tab, philo, rules, argv))
		return (2);
	// while (i < (*tab)->fork)
    // {
    //     pthread_create(&(*philo)->th, NULL, (void*)f1, NULL);
    //     i++;
    // }
    // i = 0;
    // while (i < (*tab)->fork)
    // {
    //     pthread_join(&(*philo)->th, NULL);
    //     i++;
    // }
	return (0);
}

int	main(int argc, char **argv)
{
	t_tab	*tab;
	t_philo	*philo;
	t_rules	*rules;
    long long startTime;
    long long endTime;
    
    startTime = getCurrentTimeMillis();

	if (argc == 6)
	{
		if (init_philo(&tab, &philo, &rules, argv))
			return (1);
	}
	else
	{
		printf("Look like there is not enough arguments!\n");
	}
	free(tab);

    endTime =  getCurrentTimeMillis() - startTime;
    printf("Mili : %lld mili\n", endTime);
	return (0);
}
