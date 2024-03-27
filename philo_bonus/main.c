/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:30:45 by ludovicdopp       #+#    #+#             */
/*   Updated: 2024/03/27 11:13:44 by ldoppler         ###   ########.fr       */
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
void    *philosophers(void *arg)
{
    t_philo *philo;

    philo = arg;
    printf("hello %d\n", philo->id);
    return (NULL);
}
void    start_thread(t_philo *philo)
{
    int i;

    i = 0;
    printf("nbre : %d\n", philo->rules->nbre_of_philo);
    // while (i < philo->rules->nbre_of_philo)
    // {
    //     philo[i].id = i + 1;
    //     pthread_create(&philo[i].th, NULL, &philosophers, &philo[i]);
    //     i++;
    // }
    // i = 0;
    // while (i < 5)
    // {
    //     pthread_join(philo[i].th, NULL);
    //     i++;
    // } 
}
int main(int argc, char **argv)
{
    t_philo *philo;
    t_rules *rules;

    rules = NULL;
    philo = NULL;
    if (argc >= 5 && argc <= 6)
    {
        if(check_my_args(argv + 1, argc))
        {
            printf("Please enter some valid parameter!\n");
            return (2);
        }
        init_variable(&philo, argc, argv + 1, &rules);
        start_thread(philo);
    }
    else
    {
        printf("Look like there is not enough/too much arguments!\n");
        return (2);
    }
    return (0);
}
