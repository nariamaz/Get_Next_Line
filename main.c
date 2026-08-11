/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:40:29 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/11 19:16:08 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main ()
{
    int fd = open("multiplenlx5", O_RDONLY);
    char *line;
    while((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
        if(!line)
            fd = close(fd);
    }
    return 0;
}