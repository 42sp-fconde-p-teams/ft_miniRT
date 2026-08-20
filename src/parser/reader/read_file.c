/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 13:03:49 by fconde-p          #+#    #+#             */
/*   Updated: 2026/08/20 20:17:33 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

static int	deal_with_ext_err(char *file)
{
	if (check_extention(file) == EXIT_FAILURE)
	{
		printf("Error\nFile extention must be \".rt\"!\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static void	free_split(char **split)
{
	size_t	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	deal_with_lines(char *line, int fd)
{
	char	**split_line;
	int		i;

	split_line = NULL;
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		split_line = ft_split(line, ' ');
		printf("NBR OF ELEMENTS: %zu\n", count_split_elements(split_line));
		while (split_line[i])
		{
			printf("%s\n", split_line[i]);
			i++;
		}
		free_split(split_line);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	return (EXIT_SUCCESS);
}

int	read_file(char *file)
{
	int		fd;
	char	*line;

	fd = 0;
	line = NULL;
	if (deal_with_ext_err(file) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	fd = open(file, O_RDONLY);
	deal_with_lines(line, fd);
	close(fd);
	return (EXIT_SUCCESS);
}
