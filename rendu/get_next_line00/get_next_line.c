/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:19:38 by rotrojan          #+#    #+#             */
/*   Updated: 2019/11/05 19:12:33 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		*tmp = '\0';
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
	static char		*s_buff = NULL;
	size_t			i;
	int				ret;


	if (!s_buff)
		s_buff = ft_strdup("");
	i = 0;
	while ((ret = fill_s_buff(fd, &s_buff)) > 0)
		if ((get_line_from_s_buff(&s_buff, line, &i)))
			return (1);
	while (s_buff[i])
	{
		if ((get_line_from_s_buff(&s_buff, line, &i)))
		{
			i++;
			return (1);
		}
	}
	free(s_buff);
	return (ret);
}
