/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 02:12:37 by asimonin          #+#    #+#             */
/*   Updated: 2023/06/14 22:59:25 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init(t_data *var, int ac, char **av)
{
	if (ac != 5 && ac != 6)
		print_error(var, 0);
	var->nbr_philo = ft_atoi(av[1]);
	var->time_to_die = ft_atoi(av[2]);
	var->time_to_eat = ft_atoi(av[3]);
	var->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		var->total_of_meal = ft_atoi(av[5]);
		if (var->total_of_meal <= 0)
			print_error(var, 1);
	}
	if (var->nbr_philo < 1 || var->nbr_philo > 200 || var->time_to_die < 0
		|| var->time_to_eat < 0 || var->time_to_sleep < 0)
		print_error(var, 1);
}
