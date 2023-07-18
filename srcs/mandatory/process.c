/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:07:58 by asimonin          #+#    #+#             */
/*   Updated: 2023/07/18 17:02:10 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	meal(t_philo *philo)
{
	
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
		print_status(philo, "is eating");
		usleep(400);
	}
	return (NULL);
}
