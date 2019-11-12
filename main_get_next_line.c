/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:39:17 by rotrojan          #+#    #+#             */
/*   Updated: 2019/11/12 07:14:14 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendu/get_next_line00/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	*str;
	

	(void)ac;
	str = NULL;
	if ((fd = open(av[1], O_RDONLY)) != -1)
	{
		while ((ret = get_next_line(fd, &str)) > 0)
		{
			if (ret == -1)
			{
				printf("GNL error\n");
				close(fd);
				return (0);
			}
			
			printf("ret = %d %s\n", ret, str);
			free(str);
			str = NULL;
		}
		printf("ret = %d %s\n", ret, str);
		free(str);
		close(fd);
	}
//	while (1)
//		system("leaks a.out");
	return (0);
}
