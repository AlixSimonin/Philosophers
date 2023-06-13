/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:12:36 by asimonin          #+#    #+#             */
/*   Updated: 2022/11/09 14:47:19 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if ((char)c == '\0')
		return (&((char *)s)[i]);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i--;
	}
	return (NULL);
}

/*#include <string.h>
#include <stdio.h>

int	main()
{
 	char str[] = "ouibaguette";
 	printf("%s, %s\n", strrchr(str, 'o'), ft_strrchr(str, 'o'));
}*/