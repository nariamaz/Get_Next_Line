/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 16:06:23 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/13 16:28:27 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>

char	*get_next_line(int fd)
{
	static char	*cache[MAX_FD];
	char		*buf_read;
	char		*str_return;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	buf_read = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf_read)
		return (NULL);
	str_return = (ft_read_and_search(fd, buf_read, &cache[fd]));
	free(buf_read);
	return (str_return);
}

char	*ft_read_and_search(int fd, char *buf_read, char **cache)
{
	int		bytes_read;
	char	*tmp_cache;
	int		pos_char;

	pos_char = str_search(*cache);
	while (pos_char < 0)
	{
		bytes_read = (read(fd, buf_read, (BUFFER_SIZE)));
		if (bytes_read < 0)
			return (NULL);
		buf_read[bytes_read] = '\0';
		if (bytes_read == 0)
			break ;
		tmp_cache = ft_strjoin(*cache, buf_read);
		if (!tmp_cache)
			return (NULL);
		*cache = tmp_cache;
		pos_char = str_search(*cache);
	}
	if (pos_char < 0)
		return (ft_flush_cache(cache));
	return (ft_extract_line(cache, pos_char));
}

char	*ft_extract_line(char **cache, int newline)
{
	char	*line;

	line = ft_build_line(cache, newline);
	if (!line)
		return (NULL);
	if (!ft_build_rest(cache, newline))
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*ft_build_line(char **cache, int newline)
{
	char	*line;
	int		i;

	line = ft_calloc(newline + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (i <= newline)
	{
		line[i] = (*cache)[i];
		i++;
	}
	return (line);
}

char	*ft_build_rest(char **cache, int newline)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	while ((*cache)[newline + 1 + i])
		i++;
	rest = ft_calloc(i + 1, sizeof(char));
	if (!rest)
		return (NULL);
	j = 0;
	while (j < i)
	{
		rest[j] = (*cache)[newline + 1 + j];
		j++;
	}
	free(*cache);
	*cache = rest;
	return (rest);
}
