/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:30:24 by asimonin          #+#    #+#             */
/*   Updated: 2023/07/15 01:35:20 by asimonin         ###   ########.fr       */
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

typedef struct s_philo
{
	int				index;
	int				nbr_of_meal;
	long			last_meal;
	pthread_t		thread;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	r_fork;
	
}	t_philo;

typedef struct s_data
{
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	ded_mutex;
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				total_of_meal;
	int				ded;
	long			start_time;
	t_philo	*philo;
}	t_data;



// sources //

void	print_error(t_data *var, int nbr);
void	free_all(t_data *var, int nbr);
void	init(t_data *var, int ac, char **av);
void	*routine(void *philo);

int		init_mutex(t_data *var);
int		init_philo(t_data *var);

long    gettime(void);
#endif