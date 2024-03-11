/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovicdoppler <ludovicdoppler@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:17:06 by ludovicdopp       #+#    #+#             */
/*   Updated: 2024/03/11 10:52:11 by ludovicdopp      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void *routine(void *arg)
{
    int index = *(int*)arg;
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum+=primes[index + i];
    }
    *(int*)arg = sum;
    return (arg);
}
int main(void)
{
    pthread_t th[2];

    for (int i = 0; i < 2; i++)
    {
        int *a = malloc(sizeof(int));
        *a = i * 5;
        pthread_create(&th[i], NULL, &routine, a);
    }
    int globalSum = 0;
    for (int i = 0; i < 2; i++)
    {
        int *r;
        pthread_join(th[i], &r);
        globalSum+=*r;
        free(r);
    }
    printf("Sum : %d\n", globalSum);
    return (0);
}