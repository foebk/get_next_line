/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ction <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:31:47 by ction             #+#    #+#             */
/*   Updated: 2019/04/24 18:31:48 by ction            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	ilovefree(char **tmp, char **line)
{
	char *tmp2;

	if ((*line = ft_strjoin(*line, ft_strbs(*tmp, '\n'), 12)) == 0)
		return (-1);
	tmp2 = ft_strdup(ft_strchr(*tmp, '\n') + 1);
	ft_strdel(tmp);
	*tmp = ft_strdup(tmp2);
	ft_strdel(&tmp2);
	return (1);
}

int	exit_values(char *buf, int fd, char **line, char **tmp)
{
	int	ret;

	while (ft_strnchr(buf, '\n') == -1)
	{
		if ((*line = ft_strjoin(*line, buf, 1)) == 0)
			return (-1);
		if ((ret = read(fd, buf, BUFF_SIZE)) == 0)
			return (*line[0] != '\0') ? 1 : 0;
		buf[ret] = '\0';
	}
	if (ft_strnchr(buf, '\n') != -1)
	{
		if ((*line = ft_strjoin(*line, ft_strbs(buf, '\n'), 12)) == 0)
			return (-1);
		free(*tmp);
		if ((*tmp = ft_strdup(ft_strchr(buf, '\n') + 1)) == 0)
			return (-1);
		return (1);
	}
	return (0);
}

int	lineput(const int fd, char **tmp, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	// char			*tmp;

	if (((fd < 0) || (!line) || (read(fd, buf, 0) < 0) || BUFF_SIZE < 1))
		return (-1);
	*line = ft_strnew(0);
	if ((*tmp != NULL) && (ft_strnchr(*tmp, '\n') == -1))
	{
		if ((*line = ft_strjoin(*line, *tmp, 1)) == 0)
			return (-1);
		free(*tmp);
		*tmp = NULL;
	}
	else if ((*tmp != NULL) && (ft_strnchr(*tmp, '\n') != -1))
		return (ilovefree(tmp, line));
	if ((ret = read(fd, buf, BUFF_SIZE)) == 0)
		return (*line[0] != '\0') ? 1 : 0;
	buf[ret] = '\0';
	return (exit_values(buf, fd, line, tmp));
}

int	get_next_line(const int fd, char **line)
{
	static t_list	*head;
	t_list			*lst;
	t_list			*prelst;
	int				id;
	
	prelst = NULL;
	if (head == NULL)
		if (!((head = ft_lstnew(NULL, 0))))
			return (-1);
	lst = head;
	while (lst != NULL)
		if ((lst->content_size != fd) && (prelst = lst))
			lst = lst->next;
		else
			break ;
	if (lst == NULL)
	{
		ft_pushfront(ft_lstnew(NULL, fd), &head);
		lst = head->next;
	}
	id = lineput(fd, &(lst->content), line);
	if (id == 0)
	{
		if (prelst == NULL)
		{
			prelst = head->next;
			free(head->content);
			free(head);
			head = prelst;
		}
		else
		{
			prelst->next = lst->next;
			free(lst->content);
			free(lst);
		}
	}
	return (id);
}

int main()
{
	int 	fd;
	int		fd2;
	char	*line;

	fd = open("test", O_RDONLY);
	fd2 = open("test2", O_RDONLY);
	
	printf("%d\n", get_next_line(fd, &line));
	printf("%s\n", line);
	free(line);
// 	printf("%d\n", get_next_line(fd, &line));
// 	printf("%s\n", line);
// 	free(line);
// 	printf("\n");
// 	printf("%d\n", get_next_line(fd2, &line));
// 	printf("%s\n", line);
// 	free(line);
// 	printf("%d\n", get_next_line(fd2, &line));
// 	printf("%s\n", line);
// 	free(line);
// 	printf("%d\n", get_next_line(fd2, &line));
// 	printf("%s\n", line);
// 		free(line);
// 	printf("\n");
// 	printf("%d\n", get_next_line(fd, &line));
// 	printf("%s\n", line);
// 	free(line);
// 	printf("%d\n", get_next_line(fd, &line));
// 	printf("%s\n", line);
// 	free(line);
// 	printf("%d\n", get_next_line(fd, &line));
// 	printf("%s\n", line);
// 	free(line);
// 	printf("%d\n", get_next_line(fd, &line));
// 	printf("%s\n", line);
// 	free(line);
// 	printf("%d\n", get_next_line(fd, &line));
// 	printf("%s\n", line);
// 	free(line);
}
