/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:01:17 by ldoppler          #+#    #+#             */
/*   Updated: 2024/03/11 15:32:31 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
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
	pthread_mutex_t	**mutex;
	int				fork;
}					t_tab;

typedef struct t_philo
{
    pthread_t       th;
	int				id;
	int				cur_die;
	int				cur_eat;
	int				cur_sleep;
}					t_philo;

/*utils function*/
int					ft_atoi(const char *str);

/*philo function*/
int					malloc_struct(t_tab **tab, t_philo **philo,
						t_rules **rules, char **argv);
int					init_philo(t_tab **tab, t_philo **philo, t_rules **rules,
						char **argv);
long long getCurrentTimeMillis();
#endif