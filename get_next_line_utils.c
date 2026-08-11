/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:04:30 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/11 12:36:23 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void *ft_calloc(size_t nmemb, size_t size)
{
	void*	ptr;
    unsigned int i;
    char*   cast_ptr;

    i = 0;
	ptr = NULL;
	cast_ptr = NULL;
	if (nmemb && size > (size_t)-1 / nmemb)
		return (NULL);
	if (nmemb == 0 || size == 0)
	{
		ptr = malloc (1);
		if (ptr)
			cast_ptr = 0;
		return (ptr);
	}
	ptr = malloc(nmemb * size);
	cast_ptr = (char*) ptr;
	if (ptr == NULL)
		return (NULL);
    while (i < size)
        cast_ptr[i++] = '\0';  
	return (ptr);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*string;

	string = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!string)
		return (NULL);
	i = 0;
	if (s1)
	{
		while (s1[i] != '\0')
		{
			string[i] = s1[i];
			i++;
		}
	}
	j = 0;
	while (s2[j] != '\0')
	{
		string[i] = s2[j];
		i++;
		j++;
	}
	free ((char*)s1);
	return (string);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
