/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 01:48:35 by asimonin          #+#    #+#             */
/*   Updated: 2023/06/10 20:18:46 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(t_data *var, int nbr)
{
	if (nbr == 0)
		printf("Wrong amount of arguments\n");
	else if (nbr == 1)
		printf("Please input valid arguments\n");
	exit(1);
}
