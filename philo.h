/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:01:17 by ldoppler          #+#    #+#             */
/*   Updated: 2024/03/21 13:56:30 by ldoppler         ###   ########.fr       */
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
	long long				time_to_die;
	long long				time_to_eat;
	int				time_to_sleep;
	int				nbre_philo;
	bool			someone_die;
}					t_rules;

typedef struct s_tab
{
	pthread_mutex_t			*first_fork;
	long long				global_time;
	int						fork;
}					t_tab;

typedef struct t_philo
{
	pthread_t		th;
	t_rules			*rules;
	t_tab			*tab;
	int				id;
	long long		balance;
	bool			am_i_dead_wtf_bro;
	long long		last_eat;
	int				cur_sleep;
	pthread_mutex_t	fork;
	pthread_mutex_t	fork_odd;
}					t_philo;

/*utils function*/
int					ft_atoi(const char *str);

/*philo function*/
int					malloc_struct(t_tab **tab, t_philo **philo,
						t_rules **rules, char **argv);
int					init_philo(t_tab **tab, t_philo **philo, t_rules **rules,
						char **argv);
long int			getCurrentTimeMillis(void);
int				philosophers(void *arg);
long long			get_time(long long start_time);
int	ft_usleep(long long time);
void	free_everything(t_philo *tmp);
void	kill_mutex(t_philo *tmp);
void	ft_end(t_philo *tmp);
int    check_die(t_philo *arg);
#endif