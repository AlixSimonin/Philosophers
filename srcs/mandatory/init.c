/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 02:12:37 by asimonin          #+#    #+#             */
/*   Updated: 2023/07/16 00:02:55 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_data *var)
{
	pthread_mutex_init(&var->ded_mutex, NULL);
	if (pthread_mutex_init(&var->print_mutex, NULL))
	{
		pthread_mutex_destroy(&var->ded_mutex);
		return (1);
	}
	return (0);
}

void	init(t_data *var, int ac, char **av)
{
	if (ac != 5 && ac != 6)
		print_error(var, 0);
	if (init_mutex(var))
		print_error(var, 4);
	var->nbr_philo = ft_atoi(av[1]);
	var->time_to_die = ft_atoi(av[2]);
	var->time_to_eat = ft_atoi(av[3]);
	var->time_to_sleep = ft_atoi(av[4]);
	var->total_of_meal = 0;
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

int	init_philo(t_data *var)
{
	int i;

	i = -1;
	var->start_time = gettime();
	var->philo = malloc(var->nbr_philo *sizeof(t_philo));
	if (!var->philo)
		return (1);
	while (++i < var->nbr_philo)
	{
		var->philo[i].index = i + 1;
		var->philo[i].nbr_of_meal = 0;
		var->philo[i].last_meal = 0;
		var->philo[i].data = var;
		pthread_mutex_init(&(var->philo[i].l_fork), NULL);
		var->philo[i].r_fork = var->philo[i + 1].l_fork;
		if (pthread_create(&var->philo[i].thread, NULL, &routine, (&var->philo[i])) != 0)
			print_error(var, 2);
	}
	i = -1;
	while (++i < var->nbr_philo)
		if (pthread_join(var->philo[i].thread, NULL) != 0)
			print_error(var, 3);
	return (0);
}