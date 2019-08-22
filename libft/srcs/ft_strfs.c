/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:42:49 by ction             #+#    #+#             */
/*   Updated: 2019/04/30 16:42:51 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfs(char *str, char ch)
{
	unsigned int		i;
	unsigned int		j;
	char				*dest;

	i = 0;
	j = 0;
	while (str[i] != ch)
	{
		i++;
		if (str[i] == '\0')
			return (0);
	}
	if (i == 0)
		j = 1;
	dest = malloc(sizeof(char) * (ft_strlen(str) - (i - 1 + j)));
	j = 0;
	while (str[i] != '\0')
	{
		dest[j] = str[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (dest);
}
