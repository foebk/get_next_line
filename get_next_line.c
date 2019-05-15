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
#define BUFF_SIZE 1

int	get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	static char		*tmp = NULL;

	if (((fd < 0) || (!line) || (ret = read(fd, buf, 0)) || BUFF_SIZE < 1))
		return (-1);
	*line = ft_strnew(0);
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
	if ((ret = read(fd, buf, BUFF_SIZE)) == 0)
		return (*line[0] != '\0') ? 1 : 0;	
	buf[ret] = '\0';
	while (ft_strnchr(buf, '\n') == -1)
	{
		*line = ft_strjoin(*line, buf, 1);
		if ((ret = read(fd, buf, BUFF_SIZE)) == 0)
			return (*line[0] != '\0') ? 1 : 0;
		buf[ret] = '\0';
	}
	if (ft_strnchr(buf, '\n') != -1)
	{
		*line = ft_strjoin(*line, ft_strbs(buf, '\n'), 12);
		tmp = ft_memalloc(sizeof(char) * ft_strlen(ft_strchr(buf, '\n') + 1));
		tmp = ft_strdup(ft_strchr(buf, '\n') + 1);
		return (1);
	}
	return (0);
}

int main()
{
	int 	fd;
	char	*line;

	fd = open("test", O_RDONLY);

	printf("%d\n", get_next_line(fd, &line));
	ft_putendl(line);
	printf("%d\n", get_next_line(fd, &line));
	ft_putendl(line);
	printf("%d\n", get_next_line(fd, &line));
	ft_putendl(line);
	printf("%d\n", get_next_line(fd, &line));
	ft_putendl(line);
}