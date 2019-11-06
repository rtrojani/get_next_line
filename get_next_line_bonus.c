/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:01:58 by rotrojan          #+#    #+#             */
/*   Updated: 2019/11/06 16:05:54 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	select_fd_buff(int fd, t_list **fd_buff_list)
{
	t_list		*current_link;
	t_list		*tmp_link;

	if (!*fd_buff_list)
		*fd_buff_list = ft_lstnew(fd);
	else
	{
		current_link = *fd_buff_list;
		while (current_link)
		{
			if (fd == current_link->fd)
				return ;
			tmp_link = current_link;
			current_link = current_link->next;
		}
		tmp_link->next = ft_lstnew(fd);
	}
}

int		get_line_from_s_buff(char **s_buff, char **line, size_t *i)
{
	char	*tmp;

	while ((*s_buff)[(*i)] && (*s_buff)[(*i)] != '\n')
		(*i)++;
	if ((*s_buff)[*i] == '\n')
	{
		*line = ft_substr(*s_buff, 0, *i);
		tmp = ft_strdup((*s_buff) + *i + 1);
		free(*s_buff);
		*s_buff = tmp;
		return (1);
	}
	return (0);
}

int		fill_s_buff(int fd, char **s_buff)
{
	char	r_buff[BUFFER_SIZE + 1];
	char	*tmp;
	int		ret;
	int		len;

	len = BUFFER_SIZE + 1;
	tmp = r_buff;
	while (len--)
		*tmp++ = '\0';
	if ((ret = read(fd, r_buff, BUFFER_SIZE)) > 0)
	{
		tmp = ft_strjoin(*s_buff, r_buff);
		free(*s_buff);
		*s_buff = tmp;
		return (1);
	}
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	static t_list		*fd_buff_list = NULL;
	size_t				i;
	int					ret;

	select_fd_buff(fd, &fd_buff_list);
	i = 0;
	while ((ret = fill_s_buff(fd, &(fd_buff_list->s_buff))) > 0)
		if ((get_line_from_s_buff(&(fd_buff_list->s_buff), line, &i)))
			return (1);
	while (fd_buff_list->s_buff[i])
	{
		if ((get_line_from_s_buff(&(fd_buff_list->s_buff), line, &i)))
		{
			i++;
			return (1);
		}
	}
	free(fd_buff_list->s_buff);
	return (ret);
}
