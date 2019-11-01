/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:39:17 by rotrojan          #+#    #+#             */
/*   Updated: 2019/11/01 17:11:24 by rotrojan         ###   ########.fr       */
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
	

	if (ac != 2)
		return (0);
	str = NULL;
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		while (ret == get_next_line(fd, &str))
		{
			if (ret == -1)
			{
				printf("Error\n");
				return (0);
			}
			printf("%s\n", str);
			free(str);
		}
		close(fd);
	}
	return (0);
}