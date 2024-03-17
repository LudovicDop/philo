/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovicdoppler <ludovicdoppler@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:01:17 by ldoppler          #+#    #+#             */
/*   Updated: 2024/03/17 11:53:44 by ludovicdopp      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_rules
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbre_philo;
}					t_rules;

typedef struct s_tab
{
	pthread_mutex_t	mutex;
	long long				global_time;
	pthread_mutex_t			*first_fork;
	int				fork;
}					t_tab;

typedef struct t_philo
{
    pthread_t       th;
    t_rules         *rules;
    t_tab           *tab;
	int				id;
	bool			am_i_dead_wtf_bro;
	long long				last_eat;
	int				cur_sleep;
	pthread_mutex_t			fork;
}					t_philo;

/*utils function*/
int					ft_atoi(const char *str);

/*philo function*/
int					malloc_struct(t_tab **tab, t_philo **philo,
						t_rules **rules, char **argv);
int					init_philo(t_tab **tab, t_philo **philo, t_rules **rules,
						char **argv);
long long getCurrentTimeMillis();
void	*philosophers(void *arg);
long long get_time(long long start_time);
#endif