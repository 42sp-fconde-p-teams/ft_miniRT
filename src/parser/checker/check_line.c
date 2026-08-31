/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 22:02:16 by fconde-p          #+#    #+#             */
/*   Updated: 2026/08/30 22:47:47 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

static int	check_unique_elements(char **split_line)
{
	if (check_ambience(split_line) == EXIT_SUCCESS)
	{
		printf("AMBIENCE OK\n");
		return (EXIT_SUCCESS);
	}
	else if (check_camera(split_line) == EXIT_SUCCESS)
	{
		printf("CAMERA OK\n");
		return (EXIT_SUCCESS);
	}
	else if (check_light(split_line) == EXIT_SUCCESS)
	{
		printf("LIGHT OK\n");
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
}

int	check_solid_elements(char **split_line)
{
	if (check_sphere(split_line) == EXIT_SUCCESS)
	{
		printf("SPHERE OK\n");
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
}

int	check_line(char **split_line)
{
	if (check_unique_elements(split_line) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else if (check_solid_elements(split_line) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
	{
		printf("ERROR: invalid input parameters!");
		return (EXIT_FAILURE);
	}
}
