/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 20:30:23 by rotrojan          #+#    #+#             */
/*   Updated: 2019/11/01 21:02:40 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

size_t		ft_strlen(char const *s)
{
	size_t		size;

	size = 0;
	while (*(s + size))
		size++;
	return (size);
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
