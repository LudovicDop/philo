/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:17:06 by ludovicdopp       #+#    #+#             */
/*   Updated: 2024/03/11 11:57:08 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_tab **tab, char **argv)
{
	*tab = malloc(sizeof(t_tab));
	(*tab)->fork = ft_atoi(argv[1]);
	if ((*tab)->fork < 1)
	{
		printf("Not enought philosophers!\n");
		return (free(*tab), 1);
	}
	printf("OK\n");
    return (0);
}
int	main(int argc, char **argv)
{
	t_tab	*tab;

	if (argc == 6)
	{
        if(init_philo(&tab, argv))
            return (1);
	}
	else
	{
		printf("Look like there is not enough arguments!\n");
	}
	free(tab);
	return (0);
}
