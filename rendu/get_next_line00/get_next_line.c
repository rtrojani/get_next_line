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
	t_list				*alst;
	static t_list		*current_link = NULL;
	int					ret;
	char				buff[BUFFER_SIZE];
	unsigned int		i;

	if (!current_link)
	{
		alst = ft_lstnew(fd);
		current_link = alst;
	}
	if (!current_link->str)
	{
		while ((ret = read(fd, buff, BUFFER_SIZE)))
		{
			i = 0;
			while (i < BUFFER_SIZE)
			{
				if (buff[i] == '\n')
				{
					current_link->str = ft_strndup(buff, i);
					current_link->next->str = ft_strjoin_free();
				}
			i++;
			}
		}
	}
}
