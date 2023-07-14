/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:12:27 by asimonin          #+#    #+#             */
/*   Updated: 2023/07/13 17:40:09 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long    gettime(void)
{
    struct timeval    tv;

    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
