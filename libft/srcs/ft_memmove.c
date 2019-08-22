/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:39:40 by ction             #+#    #+#             */
/*   Updated: 2019/04/06 18:39:41 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;

	if ((dest == NULL && src == NULL))
		return (NULL);
	i = 0;
	if (dest > src)
	{
		n = n - 1;
		while ((int)n != -1)
		{
			((char *)dest)[n] = ((char *)src)[n];
			n--;
		}
	}
	else
		while (i != n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	return (dest);
}
