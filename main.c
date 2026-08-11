/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:40:29 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/11 12:18:54 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main ()
{
    int fd = open("livros", O_RDONLY);
    char *line;
    while(fd)
    {
        line = get_next_line(fd);
        printf("%s\n", line);
        if(!line)
            fd = close(fd);
    }
    return 0;

    // char* string01 = NULL;
    // char string02 [] = "information here";
    // printf("%s\n", (ft_strjoin(string01, string02)));
    // return(0);
}