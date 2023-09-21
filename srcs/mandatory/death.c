/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:49:26 by asimonin          #+#    #+#             */
/*   Updated: 2023/09/21 19:16:21 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_meal(t_data *var)
{
	pthread_mutex_lock(&var->wanna_die);
	if (var->total_of_meal == 0)
	{
		pthread_mutex_lock(&var->ded_mutex);
		var->stap = 1;
		pthread_mutex_unlock(&var->ded_mutex);
		pthread_mutex_unlock(&var->wanna_die);
		return (1);
	}
	pthread_mutex_unlock(&var->wanna_die);
	return (0);
}

void	*good_bye_mf(t_data	*var, int i)
{
	long	time;

	time = gettime() - var->start_time;
	pthread_mutex_lock(&(var)->print_mutex);
	printf("[%li] %i died\n", time, i);
	pthread_mutex_unlock(&(var)->print_mutex);
	return (NULL);
}

void	*big_bro(t_data *var)
{
	int		i;
	long	time;

	while (1)
	{
		i = -1;
		while (++i < var->nbr_philo)
		{
			pthread_mutex_lock(&var->lock);
			time = gettime() - var->philo->last_meal;
			pthread_mutex_unlock(&var->lock);
			if (time >= var->time_to_die)
			{
				pthread_mutex_lock(&var->ded_mutex);
				var->stap = 1;
				pthread_mutex_unlock(&var->ded_mutex);
				return (good_bye_mf(var, i + 1));
			}
			if (check_meal(var))
				return (NULL);
		}
		usleep(50);
	}
	return (NULL);
}
