/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimonin <asimonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:53:50 by asimonin          #+#    #+#             */
/*   Updated: 2023/02/04 17:49:46 by asimonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	printf("%d", ft_isdigit ("72rg87637"));
	printf("%d", ft_isdigit ("577257"));
	printf("%d", ft_isdigit (""));
	return (0);
}*/
