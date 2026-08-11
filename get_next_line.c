/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:04:16 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/10 21:00:39 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>


char	*ft_strjoin_free(char *buffer_rest, char *buffer)
{
	char	*result;

	if (buffer == NULL)
		return (buffer_rest);
	result = ft_strjoin(buffer_rest, buffer);
	free(buffer_rest);
	return (result);
}

char *get_next_line(int fd)
{
    static char* accumulator;
    char* buf_read;
    int pos_character;
    char* str_char;
    char* str_return;

    buf_read = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!buf_read)
        return (NULL);
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
        
    pos_character = ft_read_and_search(fd, buf_read);
    while (pos_character < 0)
    {
        accumulator = ft_strjoin_free(accumulator, buf_read);
        //free (buf_read);
        pos_character = ft_read_and_search (fd, buf_read);
    }
    str_return = ft_strjoin (str_return, accumulator);
    &str_return[ultimo indice] = ft_extract_line (buf_read, (pos_character + 2));

    free (accumulator);
// get_leftover
    return (str_return);
}

int ft_read_and_search(int fd, char* buf_read)
{
    int bytes_read;
    int char_pos;
    int i;
    
    char_pos = 0;
    bytes_read = (read (fd, buf_read, (BUFFER_SIZE)));
    if (bytes_read <= 0)
    {
        free (buf_read);
        return (0);
    }
    char_pos = -1;
    i = 0;
    while (buf_read[i] != '\0')
    {
        if (buf_read[i] == CHARACTER)
            char_pos = i;    
        i++; 
    }
    return (char_pos);    
}

char *ft_extract_line (char *src, size_t nmeb)
{
    char* dest;
    int i;
    
    dest = ft_calloc(nmeb, sizeof(char));
    i = 0;
    while (i < nmeb)
	{
		dest[i] = src[i];
		i++;
	}
	dest[nmeb] = '\0';
	return (dest);
}
    




    

// int str_search(char *str)
// {
//     int position;
//     int i;

//     position = -1;
//     i = 0;
//     while (str[i] != '\0')
//     {
//         if (str[i] == CHARACTER)
//             position = i;    
//         i++; 
//     }
//     return (position);
// }