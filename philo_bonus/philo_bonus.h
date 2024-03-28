/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:19:07 by ldoppler          #+#    #+#             */
/*   Updated: 2024/03/28 14:36:23 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <semaphore.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

typedef struct s_rules
{
	int			time_before_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nbre_of_philo;
	int			how_many_dinner;
	int			someone_die;
	long		start_time;
	sem_t		fork;
	sem_t		odd;
	sem_t		die;
}				t_rules;

typedef struct s_philo
{
	int			id;
	long		last_time_eat;
	pthread_t	th;
	pthread_t	th_odd;
	t_rules		*rules;
}				t_philo;

int				ft_atoi(const char *str);
int				check_my_args(char **argv, int argc);
void			init_variable(t_philo **philo, int argc, char **argv,
					t_rules **rules);
int				philosophers(void *arg);
int				ft_usleep(long long milliseconds, t_philo *philo);
long int		get_current_time(void);
int				check_die(t_philo *philo);
int				only_one(t_philo *philo);
int				ft_printf(t_philo *philo, char *string, long long sleep);
int				ft_atoi(const char *str);
#endif