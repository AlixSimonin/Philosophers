/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:34:55 by asimonin          #+#    #+#             */
/*   Updated: 2023/07/21 17:23:40 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_l_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo)->l_fork);
	philo->left = 1;
	if (print_status(philo, "has taken a fork"))
		return (1);
	return (0);
}

int	take_r_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	philo->right = 1;
	if (print_status(philo, "has taken a fork"))
		return (1);
	return (0);
}

int	takefork(t_philo *philo)
{
	if (philo->index % 2)
	{
		if (take_r_fork(philo))
			return (1);
		if (take_l_fork(philo))
			return (1);
	}
	else
	{
		if (take_l_fork(philo))
			return (1);
		if (philo->left == philo->right)
			return (1);
		if (take_r_fork(philo))
			return (1);
	}
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
	philo->last_meal = gettime();
	if (print_status(philo, "is eating"))
	{
		pthread_mutex_unlock(&(philo)->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (1);
	}
	philo->data->total_of_meal--;
	ft_usleep(philo->data->time_to_eat);
	if (drop_fork(philo))
		return (1);
	philo -> left = 0;
	pthread_mutex_unlock(&(philo)->l_fork);
	philo -> right = 0;
	pthread_mutex_unlock(philo->r_fork);
	return (0);
}
