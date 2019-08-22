/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:21:36 by ction             #+#    #+#             */
/*   Updated: 2019/04/10 17:21:38 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int						i;
	int						multiplier;
	long long int			res;
	long long int			check;

	res = 0;
	multiplier = 1;
	i = 0;
	while (((str[i] >= 9) && (str[i] <= 13)) || (str[i] == ' '))
		i++;
	str[i] == '-' ? multiplier = -1 : (0);
	multiplier == -1 ? i++ : (0);
	((str[i] == '+') && (multiplier > 0)) ? i++ : (0);
	while (str[i] != '\0')
	{
		if (str[i] >= 58 || str[i] <= 47)
			return (res * multiplier);
		check = res;
		res = (str[i] - 48) + res * 10;
		if (((str[i] - '0') != (res % 10)) || ((check > res) && (check > 0)) ||
			((check < res) && (check < 0)))
			return (multiplier < 0) ? 0 : -1;
		i++;
	}
	return (res * multiplier);
}
