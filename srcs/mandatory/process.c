/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:07:58 by asimonin          #+#    #+#             */
/*   Updated: 2023/07/19 17:41:57 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_ded(t_philo *philo, int still_alive)
{
	pthread_mutex_lock(&(philo)->data->ded_mutex);
	if (still_alive)
		philo->data->stap = 1;
	if (philo->data->stap)
	{
		pthread_mutex_unlock(&(philo)->data->ded_mutex);
		return (1);
	}
	pthread_mutex_unlock(&(philo)->data->ded_mutex);
	return (0);
}

void	*big_bro(void *philo)
{
	t_philo	*tmp;
	long	t;
	long	m;

	tmp = (t_philo *)philo;
	while (check_ded(tmp, 0) == 0)
	{
		// pthread_mutex_lock(&(tmp)->data->lock);
		t = gettime() - tmp->data->start_time;
		m = t - tmp->last_meal;
		if (m >= tmp->data->time_to_die)
		{
			pthread_mutex_lock(&(tmp)->data->print_mutex);
			printf("[%06li] %i died\n", t, tmp->index);
			pthread_mutex_unlock(&(tmp)->data->print_mutex);
			check_ded(philo, 1);
			// pthread_mutex_unlock(&(tmp)->data->lock);
		}
		// pthread_mutex_unlock(&(tmp)->data->lock);
	}
	return (NULL);
}

void	*process(void *philo)
{
	t_philo		*tmp;
	pthread_t	oui;

	tmp = (t_philo *)philo;
	if (pthread_create(&oui, NULL, &big_bro, tmp) != 0)
		print_error(tmp->data, 2);
	if (tmp->index % 2 == 0)
		ft_usleep(tmp->data->time_to_eat);
	while (check_ded(tmp, 0) == 0)
	{
		meal(tmp);
		if (tmp->data->total_of_meal == tmp->nbr_of_meal)
		{
			check_ded(tmp, 2);
		}
		print_status(tmp, "is thinking");
	}
	if (pthread_join(oui, NULL) != 0)
		print_error(tmp->data, 3);
	return (NULL);
}
