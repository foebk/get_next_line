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
#define BUFF_SIZE 100000

static int	get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	static char		*tmp = NULL;

	*line = ft_memalloc(1);
	if ((tmp != NULL) && (ft_strnchr(tmp, '\n') == -1))
	{
		*line = ft_strjoin(*line, tmp, 1);
		tmp = NULL;
	}
	else if ((tmp != NULL) && (ft_strnchr(tmp, '\n') != -1))
	{
		*line = ft_strjoin(*line, ft_strbs(tmp, '\n'), 12);
		tmp = ft_strchr(tmp, '\n') + 1;
		return (1);
	}
	if (tmp == NULL)
		if ((ret = read(fd, buf, BUFF_SIZE)) == 0)
			return (-1);
	buf[ret] = '\0';
	while (ft_strnchr(buf, '\n') == -1)
	{
		*line = ft_strjoin(*line, buf, 1);
		if ((ret = read(fd, buf, BUFF_SIZE)) == 0)
			return (-1);
		buf[ret] = '\0';
	}
	if (ft_strnchr(buf, '\n') != -1)
	{
		*line = ft_strjoin(*line, ft_strbs(buf, '\n'), 12);
		tmp = ft_memalloc(sizeof(char) * ft_strlen(ft_strchr(buf, '\n') + 1));
		tmp = ft_strdup(ft_strchr(buf, '\n') + 1);
		return (1);
	}
}

// int main()
// {
// 	int 	fd;
// 	char	*line;
// 	char	buf[BUFF_SIZE + 1];

// 	fd = open("test", O_RDONLY);	
// 	get_next_line(fd, &line);
// 	ft_putendl(line);
// 	get_next_line(fd, &line);
// 	ft_putendl(line);
// 	get_next_line(fd, &line);
// 	ft_putendl(line);
// 	get_next_line(fd, &line);
// 	ft_putendl(line);
// }
