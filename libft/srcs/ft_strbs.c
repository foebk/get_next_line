/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 21:01:48 by ction             #+#    #+#             */
/*   Updated: 2019/04/25 21:01:50 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strbs(char *str, char ch)
{
	unsigned int		i;
	unsigned int		j;
	char				*dest;

	i = 0;
	while (str[i] != ch)
	{
		i++;
		if (str[i] == '\0')
			return (0);
	}
	dest = malloc(sizeof(char) * (i + 1));
	j = 0;
	while (j != i)
	{
		dest[j] = str[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
