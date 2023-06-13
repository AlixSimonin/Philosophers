/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:21:06 by asimonin          #+#    #+#             */
/*   Updated: 2022/11/14 18:23:46 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_src;
	size_t	len_dest;

	j = 0;
	len_src = ft_strlen(src);
	if (size == 0)
		return (size + len_src);
	len_dest = ft_strlen(dest);
	if (size <= len_dest)
		return (size + len_src);
	i = len_dest;
	while (src[j] && (j + 1 + len_dest) < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (len_src + len_dest);
}
