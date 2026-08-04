/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:04:16 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/04 20:01:05 by maridos-         ###   ########.fr       */
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

int str_search (char *str)
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
    char* buf_read;
    int processed_bytes;
    
    processed_bytes = 0;
    buf_read = NULL;
    buf_read = malloc(sizeof(char) * (BUFFER_SIZE +1));
    if (!buf_read)
        return (NULL);
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    processed_bytes = (read (fd, buf_read, (BUFFER_SIZE)));
    if (processed_bytes > 0)
        str_search ();
    

    return ();
}