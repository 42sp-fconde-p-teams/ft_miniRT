/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extention.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 18:46:02 by fconde-p          #+#    #+#             */
/*   Updated: 2026/08/08 11:46:05 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static int	check_file_lenght(char *file_name)
{
	if (ft_strlen(file_name) < 4)
	{
		printf("Error\nFile must be more than 3 characters!\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	is_null(char *file_name)
{
	if (file_name == NULL)
	{
		printf("Error\nFilename NULL!\n");
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	check_extention(char *file_name)
{
	int		ext_ending;
	char	*str;

	ext_ending = 0;
	str = NULL;
	if (check_file_lenght(file_name) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (is_null(file_name) == EXIT_SUCCESS)
		return (EXIT_FAILURE);
	ext_ending = ft_strlen(file_name) - 3;
	str = ft_substr(file_name, ext_ending, 3);
	if (str != NULL)
	{
		if (ft_strncmp(str, ".rt", 3) == 0)
		{
			free(str);
			return (EXIT_SUCCESS);
		}
		free(str);
		return (EXIT_FAILURE);
	}
	else
		return (EXIT_FAILURE);
}
