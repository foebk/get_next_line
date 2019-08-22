/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 20:33:49 by ction             #+#    #+#             */
/*   Updated: 2019/04/16 20:33:51 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*dest;
	unsigned int		i;

	i = 0;
	if ((f == NULL) || (s == NULL) || ((ft_strlen(s) + 1) == 0))
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (dest == NULL)
		return (NULL);
	while (*s != '\0')
	{
		dest[i] = (*f)(i, *s);
		i++;
		s++;
	}
	dest[i] = '\0';
	return (dest);
}
