/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 02:12:37 by asimonin          #+#    #+#             */
/*   Updated: 2023/09/21 18:38:49 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_thread(t_data *var, t_stalking *sang_woo)
{
	int	i;

	if (pthread_join(sang_woo->killing, NULL) != 0)
		print_error(3);
	i = -1;
	while (++i < var->nbr_philo)
		if (pthread_join(var->philo[i].thread, NULL) != 0)
			print_error(3);
}

int	init_mutex(t_data *var)
{
	pthread_mutex_init(&var->ded_mutex, NULL);
	if (pthread_mutex_init(&var->print_mutex, NULL))
	{
		pthread_mutex_destroy(&var->ded_mutex);
		return (1);
	}
	if (pthread_mutex_init(&var->lock, NULL))
	{
		pthread_mutex_destroy(&var->ded_mutex);
		pthread_mutex_destroy(&var->print_mutex);
		return (1);
	}
	if (pthread_mutex_init(&var->wanna_die, NULL))
	{
		pthread_mutex_destroy(&var->ded_mutex);
		pthread_mutex_destroy(&var->print_mutex);
		pthread_mutex_destroy(&var->lock);
		return (1);
	}
	return (0);
}

void	init_struct(t_data *var)
{
	int	i;

	i = -1;
	var->philo = malloc(var->nbr_philo * sizeof(t_philo));
	if (!var->philo)
		return (print_error(5));
	memset(var->philo, 0, sizeof(t_philo) * var->nbr_philo);
	var->start_time = gettime();
	while (++i < var->nbr_philo)
	{
		var->philo[i].index = i + 1;
		var->philo[i].data = var;
		var->philo[i].last_meal = var->start_time;
		pthread_mutex_init(&(var->philo[i].l_fork), NULL);
		if (i == var->nbr_philo - 1)
			var->philo[i].r_fork = &var->philo[0].l_fork;
		else
			var->philo[i].r_fork = &var->philo[i + 1].l_fork;
	}
}

int	init(t_data *var, int ac, char **av)
{
	if (init_mutex(var))
		return (print_error(4), 1);
	var->nbr_philo = ft_atoi(av[1]);
	var->time_to_die = ft_atoi(av[2]);
	var->time_to_eat = ft_atoi(av[3]);
	var->time_to_sleep = ft_atoi(av[4]);
	var->total_of_meal = 2147483647;
	if (ac == 6)
	{
		var->total_of_meal = ft_atoi(av[5]);
		var->total_of_meal *= var->nbr_philo;
		if (var->total_of_meal <= 0)
			return (print_error(1), 1);
	}
	if (var->nbr_philo < 1 || var->nbr_philo > 200 || var->time_to_die <= 10
		|| var->time_to_eat <= 10 || var->time_to_sleep <= 10)
		return (print_error(1), 1);
	init_struct(var);
	return (0);
}

int	init_philo(t_data *var, t_philo *philo)
{
	int			i;
	t_stalking	sang_woo;

	memset(&sang_woo, 0, sizeof(t_stalking));
	sang_woo.data = var;
	sang_woo.philo = philo;
	if (pthread_create(&sang_woo.killing, NULL, &big_bro, &sang_woo))
		return (print_error(2), 0);
	i = -1;
	while (++i < var->nbr_philo)
	{
		if (pthread_create(&var->philo[i].thread, NULL,
				&process, (&var->philo[i])) != 0)
		{
			print_error(2);
			break ;
		}
	}
	join_thread(var, &sang_woo);
	return (0);
}
