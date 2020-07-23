/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:06:35 by psan-gre          #+#    #+#             */
/*   Updated: 2019/12/02 13:57:02 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			return (&((char*)s)[i]);
		}
		i++;
	}
	if (c == '\0')
	{
		return (&((char*)s)[i]);
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	int		i;
	char	*out;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(out = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	size = 0;
	while (s1[size] != '\0')
	{
		out[size] = s1[size];
		size++;
	}
	while (s2[i] != '\0')
	{
		out[size + i] = s2[i];
		i++;
	}
	out[size + i] = '\0';
	return (out);
}

char	*ft_strdup(char *s1)
{
	char	*out;
	int		i;

	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	if (!(out = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (i >= 0)
	{
		out[i] = s1[i];
		i--;
	}
	return (out);
}

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int count;

	count = 0;
	while (src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}
