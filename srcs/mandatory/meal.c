/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:34:55 by asimonin          #+#    #+#             */
/*   Updated: 2023/10/04 19:36:19 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_lr(t_philo *philo)
{
	pthread_mutex_lock(&(philo)->l_fork);
	philo->left = 1;
	if (print_status(philo, "has taken a fork"))
		return (1);
	if (philo->data->nbr_philo == 1)
		return (1);
	pthread_mutex_lock(philo->r_fork);
	philo->right = 1;
	if (print_status(philo, "has taken a fork"))
		return (1);
	return (0);
}

int	take_rl(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	philo->right = 1;
	if (print_status(philo, "has taken a fork"))
		return (1);
	pthread_mutex_lock(&(philo)->l_fork);
	philo->left = 1;
	if (print_status(philo, "has taken a fork"))
		return (1);
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

int	meal(t_philo *philo)
{
	if (philo->nbr_of_meal == philo->data->meal)
	{
		ft_usleep(philo->data->time_to_eat * 0.5);
		return (0);
	}
	if (take_fork(philo))
		return (1);
	pthread_mutex_lock(&philo->data->lock);
	philo->last_meal = gettime();
	pthread_mutex_unlock(&philo->data->lock);
	if (print_status(philo, "is eating"))
		return (1);
	pthread_mutex_lock(&(philo)->data->wanna_die);
	philo->data->total_of_meal -= 1;
	philo->nbr_of_meal += 1;
	pthread_mutex_unlock(&(philo)->data->wanna_die);
	ft_usleep(philo->data->time_to_eat);
	philo->left = 0;
	pthread_mutex_unlock(&(philo)->l_fork);
	philo->right = 0;
	pthread_mutex_unlock(philo->r_fork);
	if (print_status(philo, "is sleeping"))
		return (1);
	ft_usleep(philo->data->time_to_sleep);
	return (0);
}
