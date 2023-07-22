/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:49:26 by asimonin          #+#    #+#             */
/*   Updated: 2023/07/22 20:22:16 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_meal(t_stalking *yoon_bum)
{
	pthread_mutex_lock(&(yoon_bum)->data->wanna_die);
	if (yoon_bum->data->total_of_meal == 0)
	{
		pthread_mutex_lock(&(yoon_bum)->data->ded_mutex);
		yoon_bum->data->stap = 1;
		pthread_mutex_unlock(&(yoon_bum)->data->ded_mutex);
		pthread_mutex_unlock(&(yoon_bum)->data->wanna_die);
		return (1);
	}
	pthread_mutex_unlock(&(yoon_bum)->data->wanna_die);
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

void	*big_bro(void *is_watching)
{
	t_stalking	*you;
	int			i;

	you = (t_stalking *)is_watching;
	while (1)
	{
		i = -1;
		while (++i < you->data->nbr_philo)
		{
			pthread_mutex_lock(&you->data->lock);
			you->time = gettime() - you->philo->last_meal;
			pthread_mutex_unlock(&you->data->lock);
			if (you->time > you->data->time_to_die)
			{
				pthread_mutex_lock(&(you)->data->ded_mutex);
				you->data->stap = 1;
				pthread_mutex_unlock(&(you)->data->ded_mutex);
				return (good_bye_mf(you->data, i + 1));
			}
			if (check_meal(you))
				return (NULL);
		}
		usleep(50);
	}
	return (NULL);
}
