/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 01:48:35 by asimonin          #+#    #+#             */
/*   Updated: 2023/09/15 19:33:53 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(int nbr)
{
	if (nbr == 0)
		printf("Wrong amount of arguments\n");
	else if (nbr == 1)
		printf("Please input valid arguments\n");
	else if (nbr == 2)
		printf("Failed to create thread\n");
	else if (nbr == 3)
		printf("Failed to join thread\n");
	else if (nbr == 4)
		printf("Mutex failed\n");
	else if (nbr == 5)
		printf("Malloc failed\n");
}

int	print_status(t_philo *philo, char *str)
{
	long	t;

	pthread_mutex_lock(&(philo)->data->print_mutex);
	if (check_ded(philo))
	{
		pthread_mutex_unlock(&(philo)->data->print_mutex);
		return (1);
	}
	t = gettime() - philo->data->start_time;
	printf("%li %i %s\n", t, philo->index, str);
	pthread_mutex_unlock(&(philo)->data->print_mutex);
	return (0);
}
