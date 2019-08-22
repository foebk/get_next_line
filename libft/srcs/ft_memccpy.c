/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:56:09 by ction             #+#    #+#             */
/*   Updated: 2019/04/06 16:56:10 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*destu;
	unsigned char	*srcu;

	if ((dest == NULL && src == NULL))
		return (NULL);
	destu = (unsigned char *)dest;
	srcu = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		destu[i] = srcu[i];
		if (destu[i] == (unsigned char)c)
			return (destu + i + 1);
		i++;
	}
	return (0);
}
