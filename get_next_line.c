/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:05:21 by conguyen          #+#    #+#             */
/*   Updated: 2021/12/28 14:47:35 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_get_newline(char **saved, int c, char **line)
{
	char	*temp;

	*line = ft_strsub(*saved, 0, c);
	if (*line == NULL)
	{
		free(*saved);
		return (-1);
	}
	temp = ft_strdup(&((*saved)[c + 1]));
	if (temp == NULL)
	{
		free(*saved);
		return (-1);
	}
	free(*saved);
	*saved = temp;
	if ((**saved) == '\0')
		ft_strdel(saved);
	return (1);
}

static int	ft_get_endofline(char **saved, char **line)
{
	int		c;

	c = 0;
	while ((*saved)[c] != '\0' && (*saved)[c] != '\n')
		c++;
	if ((*saved)[c] == '\n')
		return (ft_get_newline(saved, c, line));
	else
	{
		*line = ft_strdup(*saved);
		if (*line == NULL)
		{
			ft_strdel(saved);
			return (-1);
		}
		ft_strdel(saved);
	}
	return (1);
}

static int	ft_save_buffer(char **saved, char *buf)
{
	char	*temp;

	if (*saved != NULL)
	{
		temp = ft_strjoin(*saved, buf);
		if (temp == NULL)
		{
			free(*saved);
			return (-1);
		}
		free(*saved);
		*saved = temp;
	}
	else
	{
		*saved = ft_strdup(buf);
		if (*saved == NULL)
			return (-1);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*saved[MAX_FD];
	int			ret;

	if (fd < 0 || fd >= 4096 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	if (saved[fd] != NULL)
		if (ft_strchr(saved[fd], '\n') != NULL)
			return (ft_get_endofline(&saved[fd], line));
	ret = 1;
	while (ret)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret < 0)
			return (-1);
		if (ret == 0 && saved[fd] == NULL)
			return (0);
		buf[ret] = '\0';
		if (ft_save_buffer(&saved[fd], buf) == -1)
			return (-1);
		else
			if (saved[fd] != NULL && ft_strchr(saved[fd], '\n') != NULL)
				break ;
	}
	return (ft_get_endofline(&saved[fd], line));
}
