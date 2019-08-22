/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:51:05 by ction             #+#    #+#             */
/*   Updated: 2019/04/18 18:51:07 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (alst == NULL || *alst == NULL)
		return ;
	if (del == NULL)
		return ;
	while (*alst)
	{
		tmp = (*alst)->next;
		del(((*alst)->content), (*alst)->content_size);
		free(*alst);
		*alst = NULL;
		*alst = tmp;
	}
}
