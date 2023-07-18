/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:07:58 by asimonin          #+#    #+#             */
/*   Updated: 2023/07/18 20:35:34 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	meal(t_philo *philo)
{
	if (philo->data->total_of_meal != 0 && philo->data->total_of_meal
		> philo->nbr_of_meal)
	{
		//take fork
		print_status(philo, "has taken a fork");
		print_status(philo, "is eating");
		//usleep
		philo->nbr_of_meal += 1;
		philo->last_meal = 0;
		return (0);
	}
	else
		return (1);
}

int	check_ded(t_philo *philo)
{
	pthread_mutex_lock(&(philo)->data->ded_mutex);
	if (philo->data->ded == 1)
	{
		pthread_mutex_unlock(&(philo)->data->ded_mutex);
		return (1);
	}
	pthread_mutex_unlock(&(philo)->data->ded_mutex);
	return (0);
}

void	death(t_philo *philo)
{
	long	m;
	long	t;

	while (1)
	{
		t = gettime() - philo->data->start_time;
		m = t - philo->last_meal;
		if (m > philo->data->time_to_die)
		{
			pthread_mutex_lock(&(philo)->data->print_mutex);
			printf("[%06li] %i died\n", t, philo->index);
			pthread_mutex_unlock(&(philo)->data->print_mutex);
			philo->data->ded = 1;
			return ;
		}
	}
}

void	*routine(void *philo)
{
	t_philo	*tmp;
	long	r;

	tmp = (t_philo *)philo;
	r = gettime() - tmp->data->start_time;
	while (!check_ded(tmp))
	{
		meal(philo);
		usleep(400);
	}
	return (NULL);
}
