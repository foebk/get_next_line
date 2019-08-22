/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 23:23:12 by ction             #+#    #+#             */
/*   Updated: 2019/04/06 23:23:13 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned int i;

	i = 0;
	while (i != n)
	{
		if (((char *)arr)[i] == ((char)c))
		{
			return ((void *)arr + i);
		}
		i++;
	}
	return (NULL);
}
