/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:01:58 by rotrojan          #+#    #+#             */
/*   Updated: 2019/11/08 19:29:56 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void			select_fd_buff(int fd, t_list **fd_buff_list)
{
	if (!*fd_buff_list)
		fd_buff_list =
}

static int		append_line(char **s_buff, char **line, int fd, ssize_t ret)
{
	char	*tmp;

	tmp = *s_buff;
	while (*tmp && *tmp != '\n')
		tmp++;
	if (*tmp == '\n')
	{
		if (!(*line = ft_substr(*s_buff, 0, (size_t)(tmp - *s_buff))))
			return (-1);
		if (!(tmp = ft_strdup(++tmp)))
			return (-1);
		free(*s_buff);
		*s_buff = tmp;
	}
	else if (!*tmp)
	{
		if (ret == BUFFER_SIZE)
			get_next_line(fd, line);
		if (!(*line = ft_strdup(*s_buff)))
			return (-1);
		free(*s_buff);
		*s_buff = NULL;
		return (0);
	}
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static t_list		*fd_buff_list = NULL;
	char			r_buff[BUFFER_SIZE + 1];
	char			*tmp;
	ssize_t			ret;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	select_fd_buff(fd, &fd_buff_list);
	while ((ret = read(fd, r_buff, BUFFER_SIZE)) > 0)
	{
		r_buff[ret] = '\0';
		tmp = ft_strjoin(fd_buff_list->s_buff, r_buff);
		free(fd_buff_list->s_buff);
		fd_buff_list->s_buff = tmp;
		if (ft_strchr(fd_buff_list->s_buff, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	if (!ret && (!fd_buff_list->s_buff || !*fd_buff_list->s_buff))
	{
		*line = ft_strdup("");
		return (0);
	}
	return (append_line(&fd_buff_list->s_buff, line, fd, ret));
}
