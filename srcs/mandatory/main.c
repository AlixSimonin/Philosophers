/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:51:36 by asimonin          #+#    #+#             */
/*   Updated: 2023/06/14 16:32:24 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*yolo()
{
	void *o = NULL;

	printf("On mange ici\n");
	return ((void *)o);
}

int	main(int ac, char **av)
{
	t_data	var;
	int		i;

	i = -1;
	memset(&var, 0, sizeof(t_data));
	init(&var, ac, av);
	var.threads = malloc(var.nbr_philo * sizeof(pthread_t));
	if (!var.threads)
		return (1);
	pthread_mutex_init(&var.mutex, NULL);
	while (++i < var.nbr_philo)
	{
		if (pthread_create(&var.threads[i], NULL, &yolo, NULL) != 0)
			print_error(&var, 2);
		printf("Thread %d has started\n", i);
	}
	i = -1;
	while (++i < var.nbr_philo)
	{
		if (pthread_join(var.threads[i], NULL) != 0)
			print_error(&var, 3);
		printf("Thread %d has ended\n", i);
	}
	pthread_mutex_destroy(&var.mutex);
	free_all(&var, 0);
	return (0);
}
