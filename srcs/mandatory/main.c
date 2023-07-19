/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:51:36 by asimonin          #+#    #+#             */
/*   Updated: 2023/07/19 00:17:25 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	var;

	memset(&var, 0, sizeof(t_data));
	init(&var, ac, av);		
	init_philo(&var);
	free_all(&var, 0);
	return (0);
}
