/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncasecmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 15:00:04 by ction             #+#    #+#             */
/*   Updated: 2019/04/20 15:00:05 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcasecmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (((unsigned char)(ft_toupper(s1[i]))) == ((unsigned char)
			(ft_toupper(s2[i]))))
			i++;
		else
			break ;
	}
	return (((unsigned char)s1[i]) - ((unsigned char)(s2[i])));
}
