/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:40:39 by asimonin          #+#    #+#             */
/*   Updated: 2022/11/13 11:55:02 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (0);
	while (i < dstsize - 1 && s1[i] && s1[i] == s2[i])
	{
		i++;
	}
	if (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
		return (0);
	else if (((unsigned char *)s1)[i] > ((unsigned char *)s2)[i])
		return (1);
	else
		return (-1);
}
