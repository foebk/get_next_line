/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 20:55:15 by ction             #+#    #+#             */
/*   Updated: 2019/04/15 20:55:16 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long int num;

	num = (long long int)n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = num * -1;
	}
	if (num / 10 != 0)
		ft_putnbr_fd(num / 10, fd);
	if (((num % 10) >= '0') || (num % 10) <= '9')
		ft_putchar_fd(num % 10 + '0', fd);
}
