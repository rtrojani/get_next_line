/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line_multi_fd.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 02:02:39 by rotrojan          #+#    #+#             */
/*   Updated: 2019/11/12 19:10:10 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendu/get_next_line00/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	int		fd1, fd2;
	int		ret1, ret2;;
	char	*str;


	(void)ac;
	str = NULL;
	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	ret1 = 1;
	ret2 = 1;
	while (ret1 && ret2)
	{
		ret1 = get_next_line(fd1, &str);
		if (ret1 == -1)
		{
			printf("fd%d : GNL error\n", fd1);
			close(fd1);
			return (0);
		}
		printf("ret%d = %d [%s]\n", fd1, ret1, str);
		free(str);
		str = NULL;
		ret2 = get_next_line(fd2, &str);
		if (ret2 == -1)
		{
			printf("fd%d : GNL error\n", fd2);
			close(fd2);
			return (0);
		}
		printf("ret%d = %d [%s]\n", fd2, ret2, str);
		free(str);
		str = NULL;
		printf("\n");
	}
	if (!ret1)
	{

		printf("ret%d = %d [%s]\n", fd1, ret1, str);
		close(fd1);
		if (!ret2)
		{
			printf("ret%d = %d [%s]\n", fd2, ret2, str);
			close(fd2);
		}
		while ((ret2 = get_next_line(fd2, &str)))
		{
			if (ret2 == -1)
			{
				printf("fd%d : GNL error\n", fd2);
				close(fd2);
				return (0);
			}
			printf("ret%d = %d %s\n", fd2, ret2, str);
			free(str);
			str = NULL;
		}
		printf("ret%d = %d %s\n", fd2, ret2, str);
		free(str);
		close(fd2);
	}
	if (!ret2)
	{
		printf("ret%d = %d [%s]\n", fd2, ret2, str);
		close(fd2);
		if (!ret1)
		{
			printf("ret%d = %d [%s]\n", fd1, ret1, str);
			close(fd1);
		}
		while ((ret1 = get_next_line(fd1, &str)))
		{
			if (ret1 == -1)
			{
				printf("fd%d : GNL error\n", fd1);
				close(fd1);
				return (0);
			}
			printf("ret%d = %d %s\n", fd1, ret1, str);
			free(str);
			str = NULL;
		}
		printf("ret%d = %d %s\n", fd1, ret1, str);
		free(str);
		close(fd1);
	}
	system("leaks a.out");
	return (0);
}
