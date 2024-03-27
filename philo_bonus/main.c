/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:30:45 by ludovicdopp       #+#    #+#             */
/*   Updated: 2024/03/27 10:54:09 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#define NBRE_PHILO 4

// void    *routine(void *arg)
// {
//     t_philo *philo;

//     philo = arg;
//     sem_wait(&philo->sem);
//     sleep(1);
//     printf("Number : %d\n", philo->id);
//     sem_post(&philo->sem);
//     return (NULL);
// }
void    init_variable(t_philo *philo, int argc, char **argv)
{
    t_rules *rules;
    int nbre_of_philo;

    nbre_of_philo = ft_atoi(argv[0]);
    philo = malloc(sizeof(t_philo) * nbre_of_philo);
    if (!philo)
        return (exit(EXIT_FAILURE));
    rules = malloc(sizeof(t_rules));
    if (!rules)
        return (free(philo), exit(EXIT_FAILURE));
    rules->nbre_of_philo = nbre_of_philo;
    rules->time_before_die = ft_atoi(argv[1]);
    rules->time_to_eat = ft_atoi(argv[2]);
    rules->time_to_sleep = ft_atoi(argv[3]);
    if (argc == 6)
        rules->how_many_dinner = ft_atoi(argv[4]);
    else
        rules->how_many_dinner = -1;
    philo->rules = rules;
    
}

int main(int argc, char **argv)
{
    t_philo *philo;

    philo = NULL;
    if (argc >= 5 && argc <= 6)
    {
        if(check_my_args(argv + 1, argc))
        {
            printf("Please enter some valid parameter!\n");
            return (2);
        }
        init_variable(philo, argc, argv + 1);
    }
    else
    {
        printf("nok\n");
    }
    // while (i < 5)
    // {
    //     philo[i].id = i;
    //     pthread_create(&th[i], NULL, &routine, &philo[i]);
    //     i++;
    // }
    // i = 0;
    // while (i < 5)
    // {
    //     pthread_join(th[i], NULL);
    //     i++;
    // }
    return (0);
}