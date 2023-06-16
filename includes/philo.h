/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:30:24 by asimonin          #+#    #+#             */
/*   Updated: 2023/06/14 22:09:06 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# include "../libft/libft.h"

typedef struct s_data
{
	pthread_t		*threads;
	pthread_mutex_t	mutex;
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				total_of_meal;
	t_philo			*philo;
}	t_data;

typedef struct s_philo
{
	int				index;
	int				nbr_of_meal;
	int				death;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	r_fork;
	t_data			*data;
}	t_philo;

// sources //

void	print_error(t_data *var, int nbr);
void	free_all(t_data *var, int nbr);
void	init(t_data *var, int ac, char **av);

#endif