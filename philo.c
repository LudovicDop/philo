/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:47:22 by ldoppler          #+#    #+#             */
/*   Updated: 2024/03/26 18:58:22 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	i_m_eating_bis(t_philo *tmp)
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
}

int	i_m_eating(t_philo *tmp)
{
	long long	time;
	int			result;

	result = 0;
	if (!tmp->rules->someone_die)
	{
		i_m_eating_bis(tmp);
		result = ft_printf("is eating", get_time(tmp->tab->global_time), tmp,
				tmp->rules->time_to_eat);
		tmp->last_eat = get_current_time();
		pthread_mutex_unlock(&tmp->fork);
		if (tmp->id != tmp->tab->fork)
			pthread_mutex_unlock(&(tmp + 1)->fork);
		else
			pthread_mutex_unlock(tmp->tab->first_fork);
	}
	return (result);
}

int	i_m_sleeping(t_philo *tmp)
{
	return (ft_printf("is sleeping", get_time(tmp->tab->global_time), tmp,
			tmp->rules->time_to_sleep));
}

int	i_m_thinking_about_my_fucking_life(t_philo *tmp)
{
	return (ft_printf("is thinking", get_time(tmp->tab->global_time), tmp, 0));
}

int	philosophers(void *arg)
{
	t_philo	*tmp;

	tmp = (t_philo *)arg;
	if ((tmp->id % 2 == 0) || tmp->id == tmp->tab->fork)
		usleep(500);
	if (tmp->tab->fork == 1)
	{
		ft_printf("has taken a fork", get_time(tmp->tab->global_time), tmp, 0);
		tmp->rules->someone_die = 1;
		printf("%lld %d died\n", get_time(tmp->tab->global_time), tmp->id);
		return (1);
	}
	if (i_m_eating(tmp))
		return (1);
	if (i_m_sleeping(tmp))
		return (1);
	if (i_m_thinking_about_my_fucking_life(tmp))
		return (1);
	return (0);
}
