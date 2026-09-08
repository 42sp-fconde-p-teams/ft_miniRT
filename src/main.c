/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 20:37:58 by fconde-p          #+#    #+#             */
/*   Updated: 2026/09/08 14:33:57 by fconde-p         ###   ########.fr       */
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
	if (read_file(av[1], &scene) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	init_window();
	return (0);
}
