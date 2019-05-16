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

int	get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	static char		*tmp = NULL;
	char			*tmp2;

	if (((fd < 0) || (!line) || (ret = read(fd, buf, 0)) || BUFF_SIZE < 1))
		return (-1);
	*line = ft_strnew(0);
	if ((tmp != NULL) && (ft_strnchr(tmp, '\n') == -1))
	{
		if ((*line = ft_strjoin(*line, tmp, 1)) == 0)
			return (-1);
		tmp = NULL;
		free(tmp);
	}
	else if ((tmp != NULL) && (ft_strnchr(tmp, '\n') != -1))
	{
		if ((*line = ft_strjoin(*line, ft_strbs(tmp, '\n'), 12)) == 0)
			return (-1);
		tmp2 = ft_strdup(ft_strchr(tmp, '\n') + 1);
		ft_strdel(&tmp);
		tmp = ft_strdup(tmp2);
		ft_strdel(&tmp2);
		return (1);
	}
	if ((ret = read(fd, buf, BUFF_SIZE)) == 0)
		return (*line[0] != '\0') ? 1 : 0;
	buf[ret] = '\0';
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
		if ((tmp = ft_strdup(ft_strchr(buf, '\n') + 1)) == 0)
			return (-1);
		return (1);
	}
	return (0);
}

// int main()
// {
// 	int 	fd;
// 	char	*line;
// 	char	*str;
// 	int		len = 50;

// 	fd = open("test", O_RDONLY);

// 	printf("%d\n", get_next_line(fd, &line));
// 	ft_putendl(line);
// 	free(line);
// 	printf("%d\n", get_next_line(fd, &line));
// 	ft_putendl(line);
// 	free(line);
// 	printf("%d\n", get_next_line(fd, &line));
// 	ft_putendl(line);
// 	free(line);
// 	printf("%d\n", get_next_line(fd, &line));
// 	ft_putendl(line);
// 	free(line);
// }
