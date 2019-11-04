/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 20:30:23 by rotrojan          #+#    #+#             */
/*   Updated: 2019/11/04 20:51:12 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_bzero(void *b, size_t len)
{
	unsigned char	*tmp;

	tmp = (unsigned char*)b;
	while (len--)
		*(unsigned char*)tmp++ = 0;
	return (b);
}
size_t		ft_strlen(char const *s)
{
	size_t		size;

	size = 0;
	while (*(s + size))
		size++;
	return (size);
}

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	char			*cpy_dst;
	char const		*cpy_src;

	cpy_dst = dst;
	cpy_src = src;
	while (n--)
		*cpy_dst++ = *cpy_src++;
	return (dst);
}

char	*ft_strdup(char const *s1)
{
	char		*str;
	size_t		len;

	len = ft_strlen(s1) + 1;
	if (!(str = (char*)malloc(sizeof(*s1) * len)))
		return (NULL);
	return ((char*)ft_memcpy(str, s1, len));
}

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	char		*tmp;
	size_t		maxlen;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		maxlen = 0;
	else
	{
		tmp = (char*)s;
		while (len-- && *tmp)
			tmp++;
		maxlen = tmp - s;
	}
	if (!(str = (char*)malloc(sizeof(*str) * (maxlen + 1))))
		return (NULL);
	ft_bzero(str, maxlen + 1);
	return (ft_memcpy(str, s + start, maxlen));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	char			*tmp;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char*)malloc((sizeof(*tmp)
		* (ft_strlen(s1) + ft_strlen(s2) + 1)))))
		return (NULL);
	tmp = str;
	while (*s1)
		*tmp++ = *s1++;
	while (*s2)
		*tmp++ = *s2++;
	*tmp = '\0';
	return (str);
}

/*
char				*ft_strndup(char const *s1, size_t n)
{
	char			*str;
	char			*tmp;
	size_t			maxlen;

	if (!s1 || !n)
		return (NULL);
	tmp = (char*)s1;
	while (n-- && *tmp)
		tmp++;
	maxlen = (tmp - s1);
	if (!(str = (char*)malloc(sizeof(*str) * (maxlen + 1))))
		return (NULL);
	*(str + maxlen) = '\0';
	tmp = str;
	while (maxlen--)
		*tmp++ = *s1++;
	return (str);
}

size_t		ft_strlen_protected(char const *s)
{
	size_t		size;

	size = 0;
	if (s)
		while (*(s + size))
			size++;
	return (size);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char			*str;
	char			*tmp;

	if (!s1 && !s2)
		return (NULL);
	if (!(str = (char*)malloc((sizeof(*tmp)
		* (ft_strlen_protected(s1) + ft_strlen_protected(s2) + 1)))))
		return (NULL);
	tmp = str;
	if (s1)
	{
		while (*s1)
			*tmp++ = *s1++;
		free(s1);
	}
	if (s2)
	{
		while (*s2)
			*tmp++ = *s2++;
		free(s2);
	}
	*tmp = '\0';
	return (str);
}
*/
