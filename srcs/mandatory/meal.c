/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:34:55 by asimonin          #+#    #+#             */
/*   Updated: 2023/07/19 16:36:12 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo)->l_fork);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(philo->r_fork);
	print_status(philo, "has taken a fork");
}

void	drop_fork(t_philo *philo)
{
	pthread_mutex_unlock(&(philo)->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	print_status(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep);
}

void	meal(t_philo *philo)
{
	take_fork(philo);
	philo->last_meal = gettime();
	print_status(philo, "is eating");
	philo->nbr_of_meal += 1;
	ft_usleep(philo->data->time_to_eat);
	drop_fork(philo);
}
