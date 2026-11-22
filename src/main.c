/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 20:37:58 by fconde-p          #+#    #+#             */
/*   Updated: 2026/11/22 13:31:07 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

// TEMPORARY: prints all spheres in the linked list for debugging.
static void	debug_spheres(t_scene *scene)
{
	t_sphere	*current;

	current = scene->sphere;
	while (current)
	{
		printf("sphere: center=(%.1f,%.1f,%.1f) radius=%.1f color=(%d,%d,%d)\n",
			current->center.x, current->center.y, current->center.z,
			current->diameter / 2.0,
			current->color.red, current->color.green, current->color.blue);
		current = current->next;
	}
}

static void	debug_cylinders(t_scene	*scene)
{
	t_cylinder	*current;

	current = scene->cylinder;
	while (current)
	{
		printf("cylinder: center=(%.1f,%.1f,%.1f) axis=(%.4f,%.4f,%.4f) radius=%.1f height=%.1f color=(%d,%d,%d)\n",
		current->coord_center.x, current->coord_center.y, current->coord_center.z,
		current->vector.x, current->vector.y, current->vector.z,
		current->diameter,
		current->diameter / 2.0,
		current->color.red, current->color.green, current->color.blue);
		current = current->next;
	}
}

int	main(int ac, char **av)
{
	t_scene		scene;
	t_mlx_wrap	wrap;

	if (ac != 2)
	{
		printf("Error\nExpected exactly one parameter!\n");
		return (EXIT_FAILURE);
	}
	ft_bzero(&scene, sizeof(scene));
	if (read_file(av[1], &scene) == EXIT_FAILURE)
	{
		free_scene(&scene);
		printf("CHECKPOINT\n");
		return (EXIT_FAILURE);
	}
	debug_spheres(&scene);   // <- TEMPORARY DEBUG
	debug_cylinders(&scene);   // <- TEMPORARY DEBUG
	if (init_window(&scene, &wrap) == EXIT_FAILURE)
	{
		free_scene(&scene);
		return (EXIT_FAILURE);
	}
	mlx_loop(wrap.mlx);
	cleanup(&wrap);
	return (EXIT_SUCCESS);
}
