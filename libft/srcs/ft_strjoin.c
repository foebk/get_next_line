/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 21:39:07 by ction             #+#    #+#             */
/*   Updated: 2019/04/16 21:39:08 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_strjoinclear(char *s1, char *s2, int freeflag)
{
	if (freeflag == 12)
	{
		free(s1);
		free(s2);
	}
	else if (freeflag == 1)
		free(s1);
	else if (freeflag == 2)
		free(s2);
}

char			*ft_strjoin(char *s1, char *s2, int freeflag)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + (ft_strlen(s2)) + 1));
	if ((dest == NULL) || (s1 == NULL || s2 == NULL))
		return (0);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		dest[i] = s2[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	ft_strjoinclear(s1, s2, freeflag);
	return (dest);
}
