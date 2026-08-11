/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 14:58:30 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/11 14:31:33 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 10
# define CHARACTER '\n'

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> 
#include <unistd.h>

size_t	ft_strlen(const char *s);
void *ft_calloc(size_t nmemb, size_t size);
char *get_next_line(int fd);

char	*ft_strjoin(char const *s1, char const *s2);
char *ft_read_and_search(int fd, char* buf_read, char** cache);


int str_search(char *str);
char *ft_extract_line(char **cache, int newline, char* buf_read);

#endif