/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:51:06 by asimonin          #+#    #+#             */
/*   Updated: 2023/02/15 18:05:33 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_issep(char c, char sep)
{
	if (c == sep)
		return (1);
	else
		return (0);
}

int	ft_count(const char *str, char sep)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		while (str[i] && ft_issep(str[i], sep) == 1)
			i++;
		if (str[i])
			nb++;
		while (str[i] && ft_issep(str[i], sep) == 0)
			i++;
	}
	return (nb);
}

int	ft_len(const char *str, char sep, int *i)
{
	int	len;

	len = 0;
	while (str[*i] && ft_issep(str[*i], sep) == 1)
		(*i)++;
	while (str[*i + len] && ft_issep(str[*i + len], sep) == 0)
		len++;
	return (len);
}

char	*ft_strdup_split(const char *str, int len, int *i)
{
	int		j;
	char	*tab;

	j = 0;
	tab = malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	while (j < len)
	{
		tab[j] = str[*i];
		(*i)++;
		j++;
	}
	tab[j] = '\0';
	return (tab);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	int		nb;
	int		len;
	char	**dest;

	i = 0;
	j = 0;
	nb = ft_count(s, c);
	dest = malloc(sizeof(char *) * (nb + 1));
	if (!dest)
		return (NULL);
	while (i < nb)
	{
		len = ft_len(s, c, &j);
		dest[i] = ft_strdup_split(s, len, &j);
		if (dest[i] == NULL)
		{
			while (i != 0)
				free(dest[i--]);
		}
		i++;
	}
	dest[nb] = 0;
	return (dest);
}
