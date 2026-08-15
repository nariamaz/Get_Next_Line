/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maridos- <maridos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:40:29 by maridos-          #+#    #+#             */
/*   Updated: 2026/08/14 14:42:12 by maridos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int i;
	char *line;

	i = 0;
	int fd = open("test.txt", O_RDONLY);
	while (fd)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (!line)
			fd = close(fd);
		free(line);
		// if (line)
		// {
		// 	printf("call %d: [%s]\n", i, line);
		// 	free(line);
		// }
		// else
		// {
		// 	printf("call %d: [NULL]\n", i);
		// 	free(line);
		// }
		//i++;
	}
	return (0);
}
