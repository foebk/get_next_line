/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfindid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:47:47 by ction             #+#    #+#             */
/*   Updated: 2019/04/24 18:47:48 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfindid(t_list *head, size_t fd)
{
	t_list	*tmp;

	if (head = NULL)
		return (NULL);
	tmp = head->next;
	while (tmp != NULL)
	{
		if (tmp->content_size == fd)
		{
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
