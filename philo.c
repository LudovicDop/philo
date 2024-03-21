/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:47:22 by ldoppler          #+#    #+#             */
/*   Updated: 2024/03/21 15:17:36 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int    ft_printf(char *str, long long milisec, t_philo *tmp, long long sleep)
{
        if(check_die(tmp))
            return (1);
        printf("%lld %d %s\n", milisec, tmp->id, str);
        ft_usleep(sleep);
        if(check_die(tmp))
            return (1);
        return (0);
}
int    check_die(t_philo *arg)
{
    t_philo *philo;
    long long   last_eat;
    
    philo = arg;
    last_eat =  getCurrentTimeMillis() - philo->last_eat;
    if (arg->rules->someone_die)
        return (1);
    if (last_eat >= arg->rules->time_to_die)
    {
        philo->rules->someone_die = 1;
        printf("%lld %d died\n",get_time(philo->tab->global_time), arg->id);
        //ft_end(arg);
        return (1);
    }
    return (0);
}
int    i_m_eating(t_philo *tmp)
{
    long long   time;
    int result;

    result = 0;
    if (!tmp->rules->someone_die)
    {
        pthread_mutex_lock(&tmp->fork);
        ft_printf("has taken a fork", get_time(tmp->tab->global_time), tmp, 0);
        if (tmp->id != tmp->tab->fork)
        {
            pthread_mutex_lock(&(tmp + 1)->fork);
            ft_printf("has taken a fork", get_time(tmp->tab->global_time), tmp, 0);
        }
        else
        {
            pthread_mutex_lock(tmp->tab->first_fork);
            ft_printf("has taken a fork", get_time(tmp->tab->global_time), tmp, 0);
        }
        result = ft_printf("is eating", get_time(tmp->tab->global_time), tmp, tmp->rules->time_to_eat);
        tmp->last_eat = getCurrentTimeMillis();
        pthread_mutex_unlock(&tmp->fork);
        if (tmp->id != tmp->tab->fork)
            pthread_mutex_unlock(&(tmp + 1)->fork);
        else
            pthread_mutex_unlock(tmp->tab->first_fork);
    }
    return (result);
}

int    i_m_sleeping(t_philo *tmp)
{
    return (ft_printf("is sleeping", get_time(tmp->tab->global_time), tmp, tmp->rules->time_to_sleep));
}

void    i_m_thinking_about_my_fucking_life(t_philo *tmp)
{
     //ft_printf("is thinking", get_time(tmp->tab->global_time), tmp, tmp->rules->time_to_eat / 2);
     printf("%lld %d is thinking\n", get_time(tmp->tab->global_time), tmp->id);
}

int	philosophers(void *arg)
{
	t_philo *tmp;
    
	tmp = (t_philo *)arg;
    if ((tmp->id % 2 == 0) || tmp->id == tmp->tab->fork)
	{
        usleep(500);
    }
    if (i_m_eating(tmp))
    {
        //printf("KO\n");
        return (1);
    }
    if (i_m_sleeping(tmp))
    {
        //printf("KO\n");
        return (1);
    }
    i_m_thinking_about_my_fucking_life(tmp);
    return (0);
}
