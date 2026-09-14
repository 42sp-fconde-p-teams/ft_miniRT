/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 20:37:58 by fconde-p          #+#    #+#             */
/*   Updated: 2026/09/13 21:22:09 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	main(int ac, char **av)
{
	t_scene	scene;

	if (ac != 2)
	{
		printf("Error\nExpected exactly one parameter!\n");
		return (1);
	}
	ft_bzero(&scene, sizeof(scene));
	if (read_file(av[1], &scene) == EXIT_FAILURE)
	{
		// free(scene.sphere);
		printf("CHECKPOINT\n");
		return (EXIT_FAILURE);
	}
	init_window();
	// free(scene.sphere);
	return (0);
}
