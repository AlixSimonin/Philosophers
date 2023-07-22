/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:34:55 by asimonin          #+#    #+#             */
/*   Updated: 2023/07/22 14:59:18 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	take_l_fork(t_philo *philo)
// {
// 	pthread_mutex_lock(&(philo)->l_fork);
// 	if (print_status(philo, "has taken a fork"))
// 		return (1);
// 	return (0);
// }

// int	take_r_fork(t_philo *philo)
// {
// 	pthread_mutex_lock(philo->r_fork);
// 	if (print_status(philo, "has taken a fork"))
// 		return (1);
// 	return (0);
// }

// int	takefork(t_philo *philo)
// {
// 	if (take_l_fork(philo))
// 		return(1);
// 	if(take_r_fork(philo))
// 		return(1);
// 	return (0);
// 	// if (philo->index % 2)
// 	// {
// 	// 	if (take_r_fork(philo))
// 	// 		return (1);
// 	// 	if (take_l_fork(philo))
// 	// 		return (1);
// 	// }
// 	// else
// 	// {
// 	// 	if (take_l_fork(philo))
// 	// 		return (1);
// 	// 	if (philo->left == philo->right)
// 	// 		return (1);
// 	// 	if (take_r_fork(philo))
// 	// 		return (1);
// 	// }
// 	// return (0);
// }

// int	drop_fork(t_philo *philo)
// {
// 	pthread_mutex_unlock(&(philo)->l_fork);
// 	pthread_mutex_unlock(philo->r_fork);
// 	if (print_status(philo, "is sleeping"))
// 		return (1);
// 	ft_usleep(philo->data->time_to_sleep);
// 	return (0);
// }

// int	meal(t_philo *philo)
// {
// 	if (gettimeofday(&philo->kill_me, NULL))
// 		return (1);
// 	if (print_status(philo, "is eating"))
// 	{
// 		pthread_mutex_unlock(&(philo)->l_fork);
// 		pthread_mutex_unlock(philo->r_fork);
// 		return (1);
// 	}
// 	philo->data->total_of_meal--;
// 	ft_usleep(philo->data->time_to_eat);
// 	if (drop_fork(philo))
// 		return (1);
// 	philo -> left = 0;
// 	pthread_mutex_unlock(&(philo)->l_fork);
// 	philo -> right = 0;
// 	pthread_mutex_unlock(philo->r_fork);
// 	return (0);
// }

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

int	meal(t_philo *philo)
{
	take_fork(philo);
	if (gettimeofday(&philo->kill_me, NULL))
		return (1);
	print_status(philo, "is eating");
	philo->data->total_of_meal -= 1;
	ft_usleep(philo->data->time_to_eat);
	drop_fork(philo);
	return (0);
}
