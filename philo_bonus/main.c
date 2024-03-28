/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:30:45 by ludovicdopp       #+#    #+#             */
/*   Updated: 2024/03/28 11:56:55 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void    start_thread(t_philo *philo)
{
    int i;
    //int j;

    //j = 0;
    i = 0;
    //while (j < philo->rules->how_many_dinner || philo->rules->how_many_dinner == -1 && philo->rules->someone_die != 1)
    //{
        //printf("NEW\n");
        i = 0;
        while (i < philo->rules->nbre_of_philo)
        {
            philo[i].id = i + 1;
            pthread_create(&philo[i].th, NULL, (void*)&philosophers, &philo[i]);
            i++;
        }
        i = 0;
        while (i < philo->rules->nbre_of_philo)
        {
            pthread_join(philo[i].th, NULL);
            i++;
        }
        //j++;  
    //}
    printf("END\n");
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
