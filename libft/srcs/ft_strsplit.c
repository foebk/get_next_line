/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 23:18:37 by ction             #+#    #+#             */
/*   Updated: 2019/04/16 23:18:39 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strings(char const *s, char c)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			if (((s[0] != c) && (i == 0)) || ((s[i] != c) && (s[i - 1] == c)))
			{
				i++;
				words++;
			}
			else
				i++;
		}
	}
	return (words);
}

static int	ft_strlen_sym(const char *s, char c)
{
	int i;

	i = 0;
	while ((s[i] != c) && (s[i] != '\0'))
		i++;
	return (i);
}

static void	*ft_freestr(char **dest, int i)
{
	while (--i >= 0)
		free(dest[i]);
	free(dest);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**dest;
	int		i;
	int		k;
	int		j;

	i = 0;
	j = 0;
	k = 0;
	if (s == NULL)
		return (NULL);
	if (!(dest = malloc(sizeof(char *) * ft_strings(s, c) + 1)))
		return (NULL);
	while (i != (ft_strings(s, c)))
	{
		while (s[k] == c)
			k++;
		if (!(dest[i] = malloc(sizeof(char) * ft_strlen_sym((s + k), c) + 1)))
			return (ft_freestr(dest, i));
		dest[i] = ft_strndup((s + k), ft_strlen_sym((s + k), c));
		while ((s[k] != c) && (s[k] != '\0'))
			k++;
		i++;
	}
	dest[ft_strings(s, c)] = NULL;
	return (dest);
}
