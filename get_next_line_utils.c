/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:04:30 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/11 18:33:37 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_flush_cache(char** cache)
{
    char* last;
    
    if (*cache && (*cache)[0] != '\0')
    {
        last = *cache;
        *cache = NULL;
        return (last);
    }
    return (NULL);
}

void *ft_calloc(size_t nmemb, size_t size)
{
    void            *ptr;
    size_t          i;
    char            *cast_ptr;

    i = 0;
    if (nmemb && size > (size_t)-1 / nmemb)
        return (NULL);
    if (nmemb == 0 || size == 0)
    {
        ptr = malloc(1);
        if (ptr)
            *(char *)ptr = '\0';
        return (ptr);
    }
    ptr = malloc(nmemb * size);
    if (ptr == NULL)
        return (NULL);
    cast_ptr = (char *)ptr;
    while (i < nmemb * size)
        cast_ptr[i++] = '\0';
    return (ptr);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*string;

	string = ft_calloc((ft_strlen(s1) + ft_strlen(s2)) + 1, sizeof(char));
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
