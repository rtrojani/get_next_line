/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:12:55 by rotrojan          #+#    #+#             */
/*   Updated: 2019/11/01 21:11:16 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char		*entry = NULL;
	char			buff[BUFFER_SIZE];
	char			*buff_in;
	char			*buff_out;
	int				ret;
	int				i;

	ret = 0;
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		i = 0;
		while (i )
	}

	
}
