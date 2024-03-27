/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:30:45 by ludovicdopp       #+#    #+#             */
/*   Updated: 2024/03/27 10:44:58 by ldoppler         ###   ########.fr       */
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
int    init_variable(t_philo *philo, int argc, char **argv)
{
    int nbre_of_philo;

    nbre_of_philo = ft_atoi(argv[0]);
    printf("%d\n", nbre_of_philo);
    return (0);
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