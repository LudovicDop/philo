#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <time.h>

typedef struct s_thread
{
    pthread_mutex_t mutex;
} t_thread;
#endif