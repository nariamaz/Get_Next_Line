/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:04:30 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/05 17:05:45 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void *ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
    unsigned int i;
    char*   cast_ptr;

    i = 0;
    cast_ptr = (char*) ptr;
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
	if (ptr == NULL)
		return (NULL);
    while (i < size)
    {
        cast_ptr[i] = '\0';
        i++;
    }    
	return (ptr);
}
size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	size_t	src_size;
	size_t	len_copy;
    int i;

    i = 0;
	src_size = ft_strlen(src);
	if (dest_size == 0)
		return (src_size);
	if (dest_size <= src_size)
		len_copy = dest_size - 1;
	else
		len_copy = src_size;
    while (i < dest_size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[len_copy] = '\0';
	return (src_size);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_size;
	size_t	i;
	size_t	j;
	char	*string;

	if (!s1 || !s2)
		return (NULL);
	total_size = (ft_strlen(s1) + ft_strlen(s2));
	string = ft_calloc(total_size + 1, sizeof(char));
	if (!string)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		string[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		string[i] = s2[j];
		i++;
		j++;
	}
	return (string);
}