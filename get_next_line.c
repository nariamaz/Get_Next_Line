/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:04:16 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/05 17:44:21 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

/*void add_node(t_list *list)
{
    t_list *new_node;
    
    while (list->next)
        list = list->next;
    new_node = malloc(sizeof(t_list));
    if (!new_node)
        return ;
    new_node->next = NULL;
    new_node->str = NULL;
    list->next = new_node;
}*/

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

    position = 0;
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '\n')
            position = i;    
        i++; 
    }
    return (position);
}

char *get_next_line(int fd)
{
    static char* accumulator;
    char* buf_read;
    int processed_bytes;
    int has_char;
    int bytes_storaged;
    char* new_substring;
    char* str_wchar;
    size_t size;
    
    has_char = 0;
    processed_bytes = 0;
    bytes_storaged = 0;
    buf_read = calloc(BUFFER_SIZE, sizeof(char) * (BUFFER_SIZE +1));
    if (!buf_read)
        return (NULL);
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    processed_bytes = (read (fd, buf_read, (BUFFER_SIZE)));
    if (processed_bytes > 0)
        has_char = str_search (buf_read);
    else 
        return (NULL);
    if (!has_char)
    {
        if (accumulator)
            bytes_storaged = ft_strlen (accumulator);
        new_substring = &(accumulator[bytes_storaged]); 
        ft_strlcpy(new_substring, buf_read, processed_bytes);
    }
    else
    {
        size = (ft_strlen(buf_read) - has_char);
        str_wchar = calloc(size, sizeof(char));
        ft_strlcpy(str_wchar, buf_read, (has_char));
    }
    return (ft_strjoin (accumulator, str_wchar));
}
