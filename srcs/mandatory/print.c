/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 01:48:35 by asimonin          #+#    #+#             */
/*   Updated: 2023/07/19 17:41:39 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(t_data *var, int nbr)
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
	free_all(var, 1);
}

void	print_status(t_philo *philo, char *str)
{
	long	t;

	if (check_ded(philo, 0))
		return ;
	t = gettime() - philo->data->start_time;
	pthread_mutex_lock(&(philo)->data->print_mutex);
	printf("[%06li] %i %s\n", t, philo->index, str);
	pthread_mutex_unlock(&(philo)->data->print_mutex);
}
