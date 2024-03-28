/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:27:54 by ldoppler          #+#    #+#             */
/*   Updated: 2024/03/28 10:13:50 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void    init_variable(t_philo **philo, int argc, char **argv, t_rules **rules)
{
    int nbre_of_philo;
    int i;

    i = 0;
    nbre_of_philo = ft_atoi(argv[0]);
    *philo = malloc(sizeof(t_philo) * nbre_of_philo);
    if (!philo)
        return (exit(EXIT_FAILURE));
    *rules = malloc(sizeof(t_rules));
    if (!rules)
        return (free(philo), exit(EXIT_FAILURE));
    (*rules)->nbre_of_philo = nbre_of_philo;
    (*rules)->time_before_die = ft_atoi(argv[1]);
    (*rules)->time_to_eat = ft_atoi(argv[2]);
    (*rules)->time_to_sleep = ft_atoi(argv[3]);
    (*rules)->someone_die = 0;
    (*rules)->start_time = get_current_time();
    if (argc == 6)
        (*rules)->how_many_dinner = ft_atoi(argv[4]);
    else
        (*rules)->how_many_dinner = -1;
    sem_init(&(*rules)->fork, 0, (nbre_of_philo / 2));
    sem_init(&(*rules)->die, 0, 1);
    while (i < nbre_of_philo)
    {
        (*philo)[i].last_time_eat = (*rules)->start_time;
        (*philo)[i++].rules = *rules;
    }
}
