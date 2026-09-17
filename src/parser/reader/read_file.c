/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 13:03:49 by fconde-p          #+#    #+#             */
/*   Updated: 2026/09/13 18:40:43 by fconde-p         ###   ########.fr       */
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

static int	is_empty_line(char **line, int fd)
{
	int	i;

	i = ft_strlen(*line) - 1;
	if (i == 0)
	{
		free(*line);
		*line = get_next_line(fd, 0);
		return (1);
	}
	return (0);
}

static void	handle_line_error(char *line, char **split_line, int fd)
{
	ft_free_array(split_line);
	free(line);
	get_next_line(fd, 1);
}

static int	deal_with_lines(char *line, int fd, char **split_line,
	t_scene *scene)
{
	line = get_next_line(fd, 0);
	while (line)
	{
		if (is_empty_line(&line, fd))
			continue ;
		line[ft_strlen(line) - 1] = ' ';
		split_line = ft_split(line, ' ');
		if (check_line(&split_line[0], scene) == EXIT_FAILURE)
		{
			handle_line_error(line, split_line, fd);
			return (EXIT_FAILURE);
		}
		ft_free_array(split_line);
		free(line);
		line = get_next_line(fd, 0);
	}
	return (EXIT_SUCCESS);
}

int	read_file(char *file, t_scene *scene)
{
	int		fd;
	char	*line;
	char	**split_line;

	fd = 0;
	line = NULL;
	split_line = NULL;
	if (deal_with_ext_err(file) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	fd = open(file, O_RDONLY);
	deal_with_lines(line, fd, split_line, scene);
	close(fd);
	return (EXIT_SUCCESS);
}
