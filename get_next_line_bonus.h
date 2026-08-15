/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 14:58:30 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/13 16:37:35 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# ifndef CHARACTER
#  define CHARACTER '\n'
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_read_and_search(int fd, char *buf_read, char **cache);
char	*ft_extract_line(char **cache, int newline);
char	*ft_build_line(char **cache, int newline);
char	*ft_build_rest(char **cache, int newline);
char	*ft_flush_cache(char **cache);

void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
int		str_search(char *str);
size_t	ft_strlen(const char *s);

#endif
