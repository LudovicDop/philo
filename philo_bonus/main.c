/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovicdoppler <ludovicdoppler@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:30:45 by ludovicdopp       #+#    #+#             */
/*   Updated: 2024/03/24 16:17:40 by ludovicdopp      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void    *routine(void *arg)
{
    int *value;

    value = arg;
    printf("Number : %d\n", *value);
    return (NULL);
}

int main(void)
{
    pthread_t   *th;
    sem_t sem;  
    int     i;
    int       *val;

    i = 0;
    th = malloc(sizeof(pthread_t) * 4);
    val = malloc(sizeof(int));
    *val = 5;
    while (i < 5)
    {
        pthread_create(&th[i], NULL, &routine, val);
        i++;
    }
    i = 0;
    while (i < 5)
    {
        pthread_join(th[i], NULL);
        i++;
    }
    return (0);
}