#ifndef PHILO_BONUS_H
#define PHILO_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <semaphore.h>
# include <pthread.h>
# include <unistd.h>

typedef struct s_rules
{
    int time_before_die;
    int time_to_eat;
    int time_to_sleep;
    int nbre_of_philo;
    int how_many_dinner;
    sem_t fork;
} t_rules;

typedef struct s_philo
{
    int id;
    pthread_t th;
    t_rules *rules;
} t_philo;

int	ft_atoi(const char *str);
int	check_my_args(char **argv, int argc);
void    init_variable(t_philo **philo, int argc, char **argv, t_rules **rules);
#endif