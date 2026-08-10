/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:04:16 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/10 07:28:53 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int str_search(char *str)
{
    int position;
    int i;

    position = -1;
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == CHARACTER)
            position = i;    
        i++; 
    }
    return (position);
}

char *get_next_line(int fd)
{
    static char* accumulator;
    char* buf_read;
    
    int char_pos;
    int bytes_storaged;
    char* str_wchar;
    size_t size;
    
    char_pos = 0;
    bytes_storaged = 0;
    
    buf_read = ft_calloc(BUFFER_SIZE, sizeof(char) * (BUFFER_SIZE +1));
    if (!buf_read)
        return (NULL);
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    
    
    
        char_pos = str_search (buf_read);
    else
    {
        free (buf_read);
        return (NULL);
    }
    
    if (char_pos < 0)
    {
        accumulator = ft_strjoin(accumulator, buf_read);
        free (buf_read);
        return (accumulator);
    }
    else
    {
        size = (char_pos + 2);
        str_wchar = ft_calloc(size, sizeof(char));
        ft_strlcpy(str_wchar, buf_read, size);
    }
    accumulator = ft_strjoin(accumulator, str_wchar);
    return (accumulator);
}

char *ft_extract_line(fd, )
{
    int bytes_read;
    
    bytes_read = (read (fd, buf_read, (BUFFER_SIZE)));
    if (bytes_read > 0)
}