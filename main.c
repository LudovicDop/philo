/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:17:06 by ludovicdopp       #+#    #+#             */
/*   Updated: 2024/03/11 16:38:14 by ldoppler         ###   ########.fr       */
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
    printf("Fork : %d\n", (*tab)->fork);
	*philo = malloc(sizeof(t_philo) * (*tab)->fork);
	if (!(*philo))
		return (2);
	*rules = malloc(sizeof(t_rules));
	if (!(*rules))
		return (2);
	return (0);
}

void    *philosophers(void *arg)
{
    t_philo *tmp;

    tmp = (t_philo*)arg;
    printf("Hello %d\n",tmp->id);
}
int	init_philo(t_tab **tab, t_philo **philo, t_rules **rules, char **argv)
{
    int i;

    i = 0;
	if (malloc_struct(tab, philo, rules, argv))
		return (2);
	while (i < (*tab)->fork)
    {
        pthread_create(&(*philo)[i].th, NULL, (void*)philosophers, &(*philo)[i]);
        (*philo)[i].id = i;
        i++;
    }
    i = 0;
    while (i < (*tab)->fork)
    {
        pthread_join((*philo)[i].th, NULL);
        i++;
    }
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
