/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 00:06:40 by rcarmen           #+#    #+#             */
/*   Updated: 2020/12/15 13:49:22 by rcarmen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (((char *)s)[i] != '\0')
	{
		if (((char *)s)[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	if (((char *)s)[i] == (char)c)
		return (&((char *)s)[i]);
	return (NULL);
}

size_t		ft_strlen(const char *s)
{
	size_t j;

	j = 0;
	while (s[j] != '\0')
		j++;
	return (j);
}

char		*ft_strdup(const char *str)
{
	char		*mem;
	ssize_t		i;

	if (!(mem = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	i = -1;
	while (str[++i] != '\0')
		mem[i] = str[i];
	mem[i] = '\0';
	return ((char *)mem);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t				len;
	size_t				i;
	char				*mem;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(mem = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	while (*s1 != '\0')
		mem[i++] = *s1++;
	while (*s2 != '\0')
		mem[i++] = *s2++;
	mem[i] = '\0';
	return (mem);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*mem;
	size_t			i;
	size_t			sl;

	if (NULL == s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	sl = ft_strlen(s + start);
	if (sl < len)
		len = sl;
	if (!(mem = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (*s != '\0' && len > 0)
	{
		mem[i] = s[i + start];
		i++;
		len--;
	}
	mem[i] = '\0';
	return (mem);
}
