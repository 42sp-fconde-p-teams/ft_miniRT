/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 22:02:16 by fconde-p          #+#    #+#             */
/*   Updated: 2026/09/12 22:48:39 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

static int	check_unique_elements(char **split_line, t_scene *scene)
{
	if (check_ambience(split_line) == EXIT_SUCCESS)
	{
		set_ambience(split_line, scene);
		printf("AMBIENCE OK\n");
		return (EXIT_SUCCESS);
	}
	else if (check_camera(split_line) == EXIT_SUCCESS)
	{
		set_camera(split_line, scene);
		printf("CAMERA OK\n");
		return (EXIT_SUCCESS);
	}
	else if (check_light(split_line) == EXIT_SUCCESS)
	{
		set_light(split_line, scene);
		printf("LIGHT OK\n");
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
}

int	check_solid_elements(char **split_line, t_scene *scene)
{
	if (!scene)
		return (EXIT_FAILURE);
	if (check_sphere(split_line) == EXIT_SUCCESS)
	{
		set_sphere(split_line, scene);
		printf("SPHERE OK\n");
		return (EXIT_SUCCESS);
	}
	else if (check_plain(split_line) == EXIT_SUCCESS)
	{
		set_plain(split_line, scene);
		printf("PLAIN OK\n");
		return (EXIT_SUCCESS);
	}
	else if (check_cylinder(split_line) == EXIT_SUCCESS)
	{
		printf("CYLINDER OK\n");
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
}

int	check_line(char **split_line, t_scene *scene)
{
	if (!scene)
		return (EXIT_FAILURE);
	if (check_unique_elements(split_line, scene) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else if (check_solid_elements(split_line, scene) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
	{
		printf("ERROR\nInvalid input parameters!\n");
		return (EXIT_FAILURE);
	}
}
