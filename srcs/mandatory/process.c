/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:07:58 by asimonin          #+#    #+#             */
/*   Updated: 2023/07/17 21:43:53 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	long	t;

	t = gettime() - philo->last_meal;
	if (t > philo->data->time_to_eat)
	{
		philo->data->ded = 1;
	}
}

void	*routine(void *philo)
{
	t_philo	*tmp;
	long	r;

	tmp = (t_philo *)philo;
	death(tmp);
	r = gettime() - tmp->data->start_time;
	while (check_ded(tmp))
	{
		printf("[%06li] Philosoper %i is ded \n", r, tmp->index);
		return (NULL);
	}
	// else
		// printf("[%06li] Philosoper %i is eating FOOD \n", r, tmp->index);
	return (NULL);
}
