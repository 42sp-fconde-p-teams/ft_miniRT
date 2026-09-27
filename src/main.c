/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 20:37:58 by fconde-p          #+#    #+#             */
/*   Updated: 2026/09/27 10:28:22 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

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
	if (init_window(&scene, &wrap) == EXIT_FAILURE)
	{
		free_scene(&scene);
		return (EXIT_FAILURE);
	}
	mlx_loop(wrap.mlx);
	cleanup(&wrap);
	return (EXIT_SUCCESS);
}
