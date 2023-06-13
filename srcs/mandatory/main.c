/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:51:36 by asimonin          #+#    #+#             */
/*   Updated: 2023/06/13 17:47:21 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*yolo()
{
	void *o = NULL;
	printf("On mange ici\n");
	sleep(3);
	printf("Tuez moi\n");
	return ((void*)o);
}

int	main(int ac, char **av)
{
	t_data		var;
	pthread_t	non;
	pthread_t	no;

	memset(&var, 0, sizeof(t_data));
	init(&var, ac, av);
	if (pthread_create(&non, NULL, &yolo, NULL) != 0)
		return (write(2, "ERROR\n", 1));
	pthread_create(&no, NULL, &yolo, NULL);
	pthread_join(non, NULL);
	pthread_join(no, NULL);
	return (1);
}
}
