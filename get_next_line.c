/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:04:16 by maridos-          #+#    #+#             */
/*   Updated: 2026/07/31 18:43:57 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    int i = 0;
    if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 10000000)
        return (NULL);
    char var [42];
    read (fd, var, BUFFER_SIZE);
    printf ("valor de var: \n%s\n", var); 
    printf ("lina 1\n"); 
    while (var[i] != '\n')
        {
            printf("%c", var[i]);
            i++;
        }
    printf("\n");

    printf ("linha 2 \n"); 
    i++;
    while (var[i] != '\n')
        {
            printf("%c", var[i]);
            i++;
        }
    printf("\n");
    return ("error");
}