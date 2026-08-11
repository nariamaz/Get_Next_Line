/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:04:16 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/11 15:03:06 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char *get_next_line(int fd)
{
    static char* cache;
    char* buf_read;
    char* str_return;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buf_read = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!buf_read)
        return (NULL);
    str_return = ft_read_and_search(fd, buf_read, &cache);
    free(buf_read);
    return (str_return);
}

char *ft_read_and_search(int fd, char* buf_read, char** cache)
{
    int bytes_read;
    char* tmp_cache;
    int pos_char;
    
    pos_char = -1;
    while (pos_char < 0)
    {
        bytes_read = (read (fd, buf_read, (BUFFER_SIZE)));
        if (bytes_read < 0)
            return (NULL);
        buf_read[bytes_read] = '\0';
        if (bytes_read == 0)
            break;
        pos_char = str_search (buf_read);
        tmp_cache = ft_strjoin(*cache, buf_read);
        if (!tmp_cache)
            return (NULL);
        free (*cache);
        *cache = tmp_cache;   
    }
    
    return (ft_extract_line(cache, pos_char, buf_read));

  
}

char *ft_extract_line(char **cache, int newline, char* buf_read)
{
    char* tmp_cache;
    int i;
    int j;
    char* line;
    int len_cache;
    
    j = ft_strlen(*cache) - ft_strlen(buf_read);
    line = ft_calloc(newline +1, sizeof(char));
    if (!line)
        return (NULL);
    i = 0;
    while (i <= newline)
    {
        line[j + i] = *cache[j + i];
        i++;
    }
   len_cache = ft_strlen(buf_read - newline);
   tmp_cache = malloc(len_cache);
   i = 0;
   while (i++ < len_cache)
       tmp_cache[i] = *cache[j + i];
   free(cache);
   *cache = tmp_cache;
   return (line);
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