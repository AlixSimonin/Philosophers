/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:30:24 by asimonin          #+#    #+#             */
/*   Updated: 2023/07/24 15:24:09 by asimonin         ###   ########.fr       */
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


typedef struct s_philo
{
	int				index;
	int				nbr_of_meal;
	struct timeval	kill_me;
	long			last_meal;
	pthread_t		thread;
	int				left;
	int				right;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	ded_mutex;
	pthread_mutex_t	lock;
	pthread_mutex_t	wanna_die;
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				total_of_meal;
	int				stap;
	long			start_time;
	t_philo			*philo;
}	t_data;

typedef struct s_stalking
{
	pthread_t			killing;
	t_philo				*philo;
	t_data				*data;
	long				time;
}						t_stalking;

// sources //

void	print_error(t_data *var, int nbr);
void	free_all(t_data *var, int nbr);
void	init(t_data *var, int ac, char **av);
void	death(t_philo *philo);
void	join_thread(t_data *var, t_stalking *sang_woo);
void	ft_usleep(long int time);

void	*big_bro(void *is_watching);
void	*process(void *philo);

int		print_status(t_philo *philo, char *str);
int		init_mutex(t_data *var);
int		init_philo(t_data *var, t_philo *philo);
int		check_ded(t_philo *philo);
int		take_fork(t_philo *philo);
int		meal(t_philo *philo);
int		ft_atoi(const char *str);

long	gettime(void);

#endif