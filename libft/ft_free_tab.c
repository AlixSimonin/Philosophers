/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:05:59 by asimonin          #+#    #+#             */
/*   Updated: 2023/06/05 02:01:12 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = -1;
	if (!tab)
		return ;
	while (tab[++i])
		ft_free((void **)&tab[i]);
	ft_free((void **)&tab);
}