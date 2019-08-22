/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 21:23:59 by ction             #+#    #+#             */
/*   Updated: 2019/04/16 21:24:00 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	char				*dest;

	if (s == NULL)
		return (0);
	i = 0;
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (0);
	while (i != len)
	{
		if (s[start + i] == '\0')
			return (NULL);
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
