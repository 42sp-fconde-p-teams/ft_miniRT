/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 20:37:58 by fconde-p          #+#    #+#             */
/*   Updated: 2026/11/18 14:30:45 by thfernan         ###   ########.fr       */
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
	if (init_window(&scene, &wrap) == EXIT_FAILURE)
	{
		free_scene(&scene);
		return (EXIT_FAILURE);
	}
	mlx_loop(wrap.mlx);
	cleanup(&wrap);
	return (EXIT_SUCCESS);
}
