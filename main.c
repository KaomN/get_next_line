/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:27:58 by conguyen          #+#    #+#             */
/*   Updated: 2021/12/01 19:28:13 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	ft_compare(char* s1, char* s2)
{
	if (ft_atoi(s1) < ft_atoi(s2))
		return (1);
	return (0);
}

int main(void)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open("test", O_RDONLY);
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		printf("[%s]\n", line);
		free(line);
	}
	return (0);
}