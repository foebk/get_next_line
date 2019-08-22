/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:56:16 by ction             #+#    #+#             */
/*   Updated: 2019/04/09 21:56:17 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	int				begin;

	i = 0;
	if (ft_strlen(s2) == 0)
		return ((char *)(s1));
	while (s1[i] != '\0')
	{
		begin = i;
		j = 0;
		while (s2[j] != '\0')
		{
			if (s2[j] != s1[i])
				break ;
			j++;
			i++;
			if (i > len)
				return (0);
			if (s2[j] == '\0')
				return ((char *)(s1 + begin));
		}
		i = i - j + 1;
	}
	return (0);
}
