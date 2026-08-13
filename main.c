/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:40:29 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/12 23:04:04 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main ()
{
    int i;
    char *line;

    i = 0;
    int fd = open("livros", O_RDONLY);
    while((line = get_next_line(fd)) != NULL)
    {
        //printf("%s", line);
        if (line)
            printf("[%s]", line);
        else
            printf("[NULL]\n");
        free(line);
        if(!line)
            fd = close(fd);
    }
    // while (i < 7)
    // {
    //     line = get_next_line(fd);
    //     if (line)
    //     {
    //         printf("call %d: [%s]\n len=%zu\n", i, line, ft_strlen(line));
    //         free (line);
    //     }
    //     else
    //     {
    //         printf("call %d: [NULL]\n", i);
    //         free(line);
    //     }
    //     i++;
    // }
    // close(fd);
    return 0;
}