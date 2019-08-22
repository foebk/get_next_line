/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:43:55 by ction             #+#    #+#             */
/*   Updated: 2019/04/19 18:43:57 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_expmem(char *src, size_t mem)
{
	char	*dest;

	if (src == NULL)
		return (0);
	dest = malloc(sizeof(char) * (ft_strlen(src) + mem));
	ft_bzero(dest, ft_strlen(src) + mem);
	ft_strcpy(dest, src);
	free(src);
	return (dest);
}
