/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:07:58 by asimonin          #+#    #+#             */
/*   Updated: 2023/09/03 18:35:47 by asimonin         ###   ########.fr       */
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

void	*process(void *philo)
{
	t_philo		*tmp;

	tmp = (t_philo *)philo;
	if (tmp->index % 2)
		ft_usleep(tmp->data->time_to_eat / 10);
	while (1)
	{
		if (tmp->nbr_of_meal && tmp->index % 2)
			ft_usleep(tmp->data->time_to_eat / 4);
		if (meal(tmp))
			break ;
		if (print_status(tmp, "is thinking"))
			break ;
	}
	return (NULL);
}
