/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:50:42 by makacem           #+#    #+#             */
/*   Updated: 2022/03/01 15:42:59 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	if (!*str)
		return (0);
	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	unsigned int	i;
	int				s_size;

	i = 0;
	s_size = ft_strlen((char *)src);
	if (size == 0)
		return (s_size);
	while (*src && (i < size - 1 && (size != 0)))
	{
		*dst = *src;
		src++;
		dst++;
		i++;
	}
	*dst = '\0';
	return (s_size);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = ft_calloc(len, sizeof(char));
	ft_strlcpy(ptr, s1, len);
	ft_strlcpy(ptr + ft_strlen(ptr), s2, len);
	free(s1);
	free(s2);
	return (ptr);
}

char	*ft_strchr(char *s, int c)
{
	char	*ps;
	char	cc;

	cc = (char)c;
	ps = (char *)s;
	while (*ps != '\0')
	{
		if (*ps == cc)
			return (ps);
		ps++;
	}
	if (*ps == cc)
		return (ps);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	char	*c;

	ptr = NULL;
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	c = ptr;
	while (count * size > 0)
	{
		*c++ = '\0';
		count--;
	}
	return ((void *)ptr);
}
