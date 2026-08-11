/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 14:58:30 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/10 18:46:50 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 3
# define CHARACTER '\n'

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> 
#include <unistd.h>

size_t	ft_strlen(const char *s);
void *ft_calloc(size_t nmemb, size_t size);
char *get_next_line(int fd);
size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size);
char	*ft_strjoin(char const *s1, char const *s2);
int ft_read_and_search(int fd, char* buf_read);
char *ft_extract_line (char *src, size_t nmeb);

// typedef struct f_list {
//     char *str;
//     struct f_list *next;
// } t_list;


#endif