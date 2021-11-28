/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:05:21 by conguyen          #+#    #+#             */
/*   Updated: 2021/11/27 20:55:13 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

static int	ft_get_line(char **saved, char **line)
{
	int		c;
	char	*temp;

	c = 0;
	while ((*saved)[c] != '\0' && (*saved)[c] != '\n')
		c++;
	if ((*saved)[c] == '\n')
	{
		ft_strncpy(*line, *saved, c);
		temp = ft_strdup(&((*saved)[c + 1]));
		free(*saved);
		*saved = temp;
	}
	else
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
	}
	return (1);
}

static int	ft_check(char **saved, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && saved[fd] == NULL)
		return (0);
	else
		return (ft_get_line(&saved[fd], line));
}

static int	ft_save_buffer(char **saved, char **line, int ret, int fd)
{
	char	*temp;

	while (ret)
	{
		buf[ret] = '\0';
		if (saved[fd] != NULL)
		{
			temp = ft_strjoin(saved[fd], buf);
			free(saved[fd]);
			saved[fd] = tmp;
		}
		else
			saved[fd] = ft_strdup(buf);
		if (ft_strchr(saved[fd], '\n') != NULL)
			break ;
	}
	return (check_line(saved, line, ret, fd));
}

int	get_next_line(const int fd, char **line)
{
	static char	*saved[MAX_FD];
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	ret = read(fd, buf, BUFF_SIZE);
	if (ret < 0)
		return (-1);
	return (get_line(saved, line, ret, fd));
}
