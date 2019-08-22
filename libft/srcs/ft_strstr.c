/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:01:16 by ction             #+#    #+#             */
/*   Updated: 2019/04/09 21:01:22 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	unsigned int i;
	unsigned int j;
	unsigned int begin;

	i = 0;
	j = 0;
	if (ft_strlen(s2) == 0)
		return ((char *)(s1));
	while (s1[i] != '\0')
	{
		begin = i;
		while (s2[j] != '\0')
		{
			if (s2[j] != s1[i])
				break ;
			j++;
			i++;
			if (s2[j] == '\0')
				return ((char *)(s1 + begin));
		}
		i = i - j + 1;
		j = 0;
	}
	return (0);
}
