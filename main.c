/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:27:58 by conguyen          #+#    #+#             */
/*   Updated: 2021/12/16 10:20:10 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

void	test_read_stdin_redirection(void)
{
	int		fd;
	char	*line;
	int		ret;

	fd = 0;
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		printf("line:[%s] return:[%d]\n", line, ret);
		free(line);
	}
	close(fd);
}

void	test_basic(char *argv)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open(argv, O_RDONLY);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		printf("line:[%s] return:[%d]\n", line, ret);
		free(line);
	}
	close(fd);
}

void	test_multiple(char *argv1, char *argv2)
{
	int		fd1;
	int		fd2;
	char	*line;
	int		ret;

	fd1 = open(argv1, O_RDONLY);
	fd2 = open(argv2, O_RDONLY);
	for ( int x = 0; x < 3; x++)
	{
		ret = get_next_line(fd1, &line);
		printf("line:[%s] return:[%d] From fd:[%d]\n", line, ret, fd1);
		if (ret == 0)
			close(fd1);
		free(line);
		ret = get_next_line(fd2, &line);
		printf("line:[%s] return:[%d] From fd:[%d]\n", line, ret, fd2);
		free(line);
		if (ret == 0)
			close(fd2);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		test_read_stdin_redirection();
	}
	else if (argc == 2)
	{
			test_basic(argv[1]);
	}
	else if (argc == 3)
	{
		test_multiple(argv[1], argv[2]);
	}
	else
	{
		for (int x = 1; x < argc; x++)
			test_basic(argv[x]);
	}
	return (0);
}