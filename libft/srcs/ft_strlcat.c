/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:14:23 by ction             #+#    #+#             */
/*   Updated: 2019/04/09 18:26:25 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, char *src, size_t n)
{
	unsigned int		i;
	size_t				srcl;
	size_t				dstl;

	i = 0;
	dstl = ft_strlen(dest);
	srcl = ft_strlen(src);
	if (n <= dstl)
		return (srcl + n);
	while ((dest[i] != '\0') && (n - 1) > (unsigned int)i)
		i++;
	while (*src != 0 && (n - 1) > (unsigned int)i)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return (dstl + srcl);
}
