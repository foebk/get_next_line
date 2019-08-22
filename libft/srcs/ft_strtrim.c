/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 21:54:43 by ction             #+#    #+#             */
/*   Updated: 2019/04/16 21:54:45 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*dest;

	i = 0;
	j = 0;
	k = 0;
	if (s == NULL)
		return (NULL);
	while ((s[i] == ' ') || (s[i] == '\t') || s[i] == '\n')
		i++;
	j = ft_strlen(s) - 1;
	while ((s[j] == ' ') || (s[j] == '\t') || s[j] == '\n')
		j--;
	j -= i;
	if (j < 0)
		return (ft_memalloc(1));
	if (!(dest = malloc(sizeof(char) * (j + 2))))
		return (NULL);
	while (k != j + 1)
		dest[k++] = s[i++];
	dest[k] = '\0';
	return (dest);
}
