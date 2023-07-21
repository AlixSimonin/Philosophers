/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:07:58 by asimonin          #+#    #+#             */
/*   Updated: 2023/07/21 17:41:58 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_ded(t_philo *philo)
{
	int	ded;

	pthread_mutex_lock(&philo->data->ded_mutex);
	ded = philo->data->stap;
	pthread_mutex_unlock(&philo->data->ded_mutex);
	if (ded)
		return (1);
	return (0);
}


void	*big_bro(void *philo)
{
	t_philo	*tmp;
	long	t;
	long	m;

	tmp = (t_philo *)philo;
	while (check_ded(tmp) == 0)
	{
		t = gettime() - tmp->data->start_time;
		m = t - tmp->last_meal;
		if (m >= tmp->data->time_to_die)
		{
			pthread_mutex_lock(&(tmp)->data->print_mutex);
			printf("[%li] %i died\n", t, tmp->index);
			tmp->data->stap = 1;
			pthread_mutex_unlock(&(tmp)->data->print_mutex);
			check_ded(philo);
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
	while (1)
	{
		if (tmp->index % 2 == 0)
			ft_usleep(tmp->data->time_to_die * 0.25);
		if (takefork(tmp))
			break ;
		if (meal(tmp))
			break ;
		if (tmp->data->total_of_meal == 0)
		{
			tmp -> data -> stap = 1;
			check_ded(tmp);
		}
		if (print_status(tmp, "is thinking"))
			break ;
	}
	if (pthread_join(oui, NULL) != 0)
		print_error(tmp->data, 3);
	return (NULL);
}
