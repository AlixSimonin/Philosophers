/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:51:36 by asimonin          #+#    #+#             */
/*   Updated: 2023/06/13 19:24:26 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*yolo()
{
	void *o = NULL;
	printf("On mange ici\n");
	return ((void*)o);
}

int	main(int ac, char **av)
{
	t_data		var;
	int	i;
	
	i = 0;
	memset(&var, 0, sizeof(t_data));
	init(&var, ac, av);
	var.threads = malloc(var.nbr_philo * sizeof(pthread_t));
	pthread_mutex_init(&var.mutex, NULL);
	while (i < var.nbr_philo)
	{
		pthread_create(&var.threads[i], NULL, &yolo, NULL);
		printf("Thread %d has started\n", i);
		i++;
	}
	i = 0;
	while (i < var.nbr_philo)
	{
		pthread_join(var.threads[i], NULL);
		printf("Thread %d has ended\n", i);
		i++;
	}
	pthread_mutex_destroy(&var.mutex);
	return (1);
}
