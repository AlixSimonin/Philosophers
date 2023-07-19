/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:07:58 by asimonin          #+#    #+#             */
/*   Updated: 2023/07/19 02:21:54 by asimonin         ###   ########.fr       */
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

int	meal(t_philo *philo)
{
	take_fork(philo);
	philo->last_meal = gettime();
	print_status(philo, "is eating");
	philo->nbr_of_meal += 1;
	ft_usleep(philo->data->time_to_eat);
	drop_fork(philo);
	return (0);
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

void	*big_bro(void *philo)
{
	t_philo	*tmp;
	long	t;
	
	tmp = (t_philo *)philo;
	while (check_ded(tmp) == 0)
	{
		t = gettime() - tmp->data->start_time;
		if (gettime() - tmp->last_meal >= tmp->data->time_to_die)
		{
			pthread_mutex_lock(&(tmp)->data->print_mutex);
			printf("[%06li] %i died\n", t, tmp->index);
			pthread_mutex_unlock(&(tmp)->data->print_mutex);
			tmp->data->ded = 1;
		}
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
	if (tmp->data->nbr_philo % 2 == 0)
		ft_usleep(tmp->data->time_to_eat / 10);
	while (check_ded(tmp) == 0)
	{
		meal(tmp);
		print_status(tmp, "is thinking");
	}
	if (pthread_join(oui, NULL) != 0)
			print_error(tmp->data, 3);
	return (NULL);
}
