/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:23:11 by psan-gre          #+#    #+#             */
/*   Updated: 2019/12/02 18:02:14 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 36
#endif

#include "get_next_line.h"

static int	output(int r, char **stat, char **line)
{
	char *aux;
	char *tmp;

	if (r < 0)
		return (-1);
	if (*stat == NULL && r == 0)
	{
		*line = ft_strdup("");
		return (0);
	}
	else if ((aux = ft_strchr(*stat, '\n')))
	{
		*aux = 0;
		*line = ft_strdup(*stat);
		tmp = ft_strdup(++aux);
		free(*stat);
		*stat = tmp;
	}
	else
	{
		*line = *stat;
		*stat = NULL;
		return (0);
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*stat[4096];
	char		*tmp;
	int			r;
	char		buff[BUFFER_SIZE + 1];

	while ((r = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[r] = 0;
		if (stat[fd] != NULL)
		{
			tmp = ft_strjoin(stat[fd], buff);
			free(stat[fd]);
			stat[fd] = tmp;
		}
		else
		{
			stat[fd] = ft_strdup(buff);
		}
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (output(r, &stat[fd], line));
}
