/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:34:55 by asimonin          #+#    #+#             */
/*   Updated: 2023/09/03 18:34:25 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_lr(t_philo *philo)
{
	pthread_mutex_lock(&(philo)->l_fork);
	if (print_status(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(&(philo)->l_fork);
		return (1);
	}
	if (philo->data->nbr_philo == 1)
	{
		pthread_mutex_unlock(&(philo)->l_fork);
		return (1);
	}
	pthread_mutex_lock(philo->r_fork);
	if (print_status(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(&(philo)->l_fork);
		return (1);
	}
	return (0);
}

int	take_rl(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	if (print_status(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(philo->r_fork);
		return (1);
	}
	pthread_mutex_lock(&(philo)->l_fork);
	if (print_status(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(&(philo)->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (1);
	}
	return (0);
}

int	take_fork(t_philo *philo)
{
	if (philo->index % 2 == 0)
		if (take_rl(philo))
			return (1);
	if (philo->index % 2 == 1)
		if (take_lr(philo))
			return (1);
	return (0);
}

int	drop_fork(t_philo *philo)
{
	pthread_mutex_unlock(&(philo)->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	if (print_status(philo, "is sleeping"))
		return (1);
	ft_usleep(philo->data->time_to_sleep);
	return (0);
}

int	meal(t_philo *philo)
{
	pthread_mutex_lock(&(philo)->data->wanna_die);
	philo->data->total_of_meal -= 1;
	pthread_mutex_unlock(&(philo)->data->wanna_die);
	if (take_fork(philo))
		return (1);
	pthread_mutex_lock(&philo->data->lock);
	philo->last_meal = gettime();
	pthread_mutex_unlock(&philo->data->lock);
	if (print_status(philo, "is eating"))
	{
		pthread_mutex_unlock(&(philo)->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (1);
	}
	ft_usleep(philo->data->time_to_eat);
	if (drop_fork(philo))
		return (1);
	return (0);
}
