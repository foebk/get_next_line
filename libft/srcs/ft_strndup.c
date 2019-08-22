/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 21:10:05 by ction             #+#    #+#             */
/*   Updated: 2019/04/17 21:10:06 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *src, size_t n)
{
	unsigned int		count;
	char				*dest;

	count = 0;
	while ((src[count] != '\0') && (count < n))
	{
		count++;
	}
	dest = (char *)malloc(sizeof(char) * (count + 1));
	if (dest == NULL)
		return (0);
	count = 0;
	while ((src[count] != '\0') && (count < n))
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}
