/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:40:29 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/09 00:32:14 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main ()
{
    int fd = open("livros", O_RDONLY);
    //printf("%d\n", fd);
    printf("%s\n", get_next_line(fd));
    return 0;

    // char* string01 = NULL;
    // char string02 [] = "information here";
    // printf("%s\n", (ft_strjoin(string01, string02)));
    // return(0);
}