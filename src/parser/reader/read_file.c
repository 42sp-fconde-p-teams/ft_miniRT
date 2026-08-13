/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 13:03:49 by fconde-p          #+#    #+#             */
/*   Updated: 2026/08/13 12:33:34 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	read_file(char *file)
{
	int		fd;
	char	*line;

	fd = 0;
	line = NULL;
	if (check_extention(file) == EXIT_FAILURE)
	{
		printf("Error\nFile extention must be \".rt\"!\n");
		return (EXIT_FAILURE);
	}
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (EXIT_SUCCESS);
}
