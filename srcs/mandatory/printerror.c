/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 01:48:35 by asimonin          #+#    #+#             */
/*   Updated: 2023/06/14 16:33:31 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(t_data *var, int nbr)
{
	if (nbr == 0)
		printf("Wrong amount of arguments\n");
	else if (nbr == 1)
		printf("Please input valid arguments\n");
	else if (nbr == 2)
		printf("Failed to create thread\n");
	else if (nbr == 3)
		printf("Failed to join thread\n");
	free_all(var, 1);
}
