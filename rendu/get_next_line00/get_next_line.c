/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:12:55 by rotrojan          #+#    #+#             */
/*   Updated: 2019/11/04 20:42:36 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		look_for_newline(char const *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		append_line(int fd, char **line, char **static_buff)
{
	char		buff_read[BUFFER_SIZE + 1];
	int			ret;
	int			i;
	char		*tmp;

	ft_bzero(buff_read, BUFFER_SIZE + 1);
	i = 0;
	while ((ret = read(fd, buff_read, BUFFER_SIZE)) > 0)
	{
		tmp = ft_strjoin(*static_buff, buff_read);
		ft_bzero(buff_read, BUFFER_SIZE + 1);
		free(*static_buff);
		*static_buff = tmp;
//		printf("s_buff = \n[ %s ]\n", *static_buff);
		 if ((i = look_for_newline(*(static_buff + i))) != -1)
		{
			*line = ft_substr((*static_buff), 0, i);
			tmp = ft_substr(*static_buff, i + 1, ft_strlen(*static_buff) - i - 1);
			free(*static_buff);
			*static_buff = tmp;
//			printf("line = %s\n", *line);
//			printf("sbuf = [[%s]]\n", *static_buff);
			return (1);
		}
	}	
	free(*static_buff);
//	printf("s_buff = \n[ %s ]\n", *static_buff);
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	static char		*static_buff = NULL;

	if (BUFFER_SIZE <= 0)
		return (-1);
	if (!static_buff)
		static_buff = ft_strdup("");
	return (append_line(fd, line, &static_buff));
}


/*
int		read_buffer(int fd, char **tmp_buff, char **line)
{
	char		buff[BUFFER_SIZE];
	int			ret;
	size_t		i;

	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		i = 0;
		while (i < ret)
		{
			if (buff[i] == '\n')
			{
				*line = ft_strndup(buff, i - 1);
				*tmp_buff = ft_strjoin_free(*tmp_buff,
					ft_strndup(&buff[i + 1], ret - i - 1 ));
				return (ret);
			}
			i++;
		}
	}
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	static char		*tmp_buff = NULL;
	size_t			i;

	*line = NULL;
	if (!tmp_buff)
		read_buffer(fd, &tmp_buff, line);
	i = 0;
	while (tmp_buff[i])
	{
		if (tmp_buff[i] == '\n')
		{
			*line = ft_strndup(tmp_buff, i - 1);
			tmp_buff = ft_strjoin_free(tmp_buff,
				ft_strndup(&tmp_buff[i + 1],
					ft_strlen_protected(tmp_buff) - i - 1 ));
			return (1);
		}
		i++;
	}
}
*/
