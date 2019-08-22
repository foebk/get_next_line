/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 22:49:36 by ction             #+#    #+#             */
/*   Updated: 2019/04/17 22:49:38 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, int content_size)
{
	t_list	*head;

	if (!(head = (t_list *)malloc(sizeof(t_list))))
		return (0);
	if (content == NULL)
	{
		head->content = 0;
		head->content_size = content_size;
		head->next = NULL;
	}
	else if (!((head->content = malloc(sizeof(content_size)))))
	{
		free(head);
		return (0);
	}
	else
	{
		ft_memcpy(head->content, content, content_size);
		head->content_size = content_size;
		head->next = 0;
	}
	return (head);
}
