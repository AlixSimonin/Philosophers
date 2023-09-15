/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:51:36 by asimonin          #+#    #+#             */
/*   Updated: 2023/09/15 19:41:57 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	var;
	if (ac != 5 && ac != 6)
		return (print_error(0), 0);
	memset(&var, 0, sizeof(t_data));
	if (init(&var, ac, av))
		return (0);
	init_philo(&var, var.philo);
	free_all(&var, 0);
	return (0);
}
