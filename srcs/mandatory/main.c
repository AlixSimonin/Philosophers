/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:51:36 by asimonin          #+#    #+#             */
/*   Updated: 2023/07/14 15:06:57 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*yolo(void *var)
{
	void *o = NULL;
	t_data *tmp = (t_data *)var;
	sleep(1);
	int	r =  gettime() - tmp->start_time;
	printf("On mange ici %i\n", r);
	return ((void *)o);
}

int	main(int ac, char **av)
{
	t_data	var;
	int		i;

	i = -1;
	memset(&var, 0, sizeof(t_data));
	init(&var, ac, av);
	var.start_time = gettime();
	var.threads = malloc(var.nbr_philo * sizeof(pthread_t));
	if (!var.threads)
		return (1);
	pthread_mutex_init(&var.mutex, NULL);
	while (++i < var.nbr_philo)
	{
		if (pthread_create(&var.threads[i], NULL, &yolo, (&var)) != 0)
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
