/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 20:37:58 by fconde-p          #+#    #+#             */
/*   Updated: 2026/09/15 23:56:35 by fconde-p         ###   ########.fr       */
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
		free_scene(&scene);
		printf("CHECKPOINT\n");
		return (EXIT_FAILURE);
	}
	init_window(&scene);
	return (0);
}
