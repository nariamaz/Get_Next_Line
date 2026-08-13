/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:40:29 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/12 22:24:15 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main ()
{
    int i;
    char *line;

    i = 0;
    int fd = open("multiple_nlx5", O_RDONLY);
    // while((line = get_next_line(fd)) != NULL)
    // {
    //     //printf("%s", line);
    //     if (line)
    //         printf("[%s]", line);
    //     else
    //         printf("[NULL]\n");
    //     free(line);
    //     if(!line)
    //         fd = close(fd);
    // }
    while (i < 7)
{
    line = get_next_line(fd);
    if (line)
        printf("call %d: [%s] len=%zu\n", i, line, ft_strlen(line));
    else
        printf("call %d: [NULL]\n", i);
    i++;
}
    return 0;
}