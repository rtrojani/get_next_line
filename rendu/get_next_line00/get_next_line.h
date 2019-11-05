/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:16:44 by rotrojan          #+#    #+#             */
/*   Updated: 2019/11/05 13:09:45 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

int			get_next_line(int fd, char **line);
char		*ft_strdup(char const *s1);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(char const *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif
