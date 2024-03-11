#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <time.h>

typedef struct s_rules
{
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int nbre_philo;
}t_rules;

typedef struct s_tab
{
    pthread_mutex_t **mutex;
    int             fork;
};

typedef struct t_philo
{
    int id;
    int cur_die;
    int cur_eat;
    int cur_sleep;
} t_philo;

/*utils function*/
int	ft_atoi(const char *str);

/*philo function*/

#endif