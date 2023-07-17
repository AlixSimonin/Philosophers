/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:07:58 by asimonin          #+#    #+#             */
/*   Updated: 2023/07/17 19:35:21 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	death(t_philo *philo)
{
	long	t;

	t = gettime() - philo->last_meal;
	if (t > philo->data->time_to_eat)
	{
		philo->data->ded = 1;
		return (1);
	}
	return (0);
}

void	*routine(void *philo)
{
	t_philo	*tmp;
	long	r;

	tmp = (t_philo *)philo;
	r = gettime() - tmp->data->start_time;
	if (death(tmp))
		printf("[%06li] Philosoper %i is ded \n", r, tmp->index);
	printf("[%06li] Philosoper %i is eating FOOD \n", r, tmp->index);
	return (NULL);
}
