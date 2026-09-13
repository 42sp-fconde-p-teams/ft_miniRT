/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 21:44:01 by fconde-p          #+#    #+#             */
/*   Updated: 2026/09/12 21:51:07 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

int	set_camera(char **split_line, t_scene *scene)
{
	char	**split_coord;
	char	**split_vector;

	split_coord = NULL;
	split_vector = NULL;
	split_coord = ft_split(split_line[1], ',');
	split_vector = ft_split(split_line[2], ',');
	scene->camera.origin.x = ft_atod(split_coord[0]);
	scene->camera.origin.y = ft_atod(split_coord[1]);
	scene->camera.origin.z = ft_atod(split_coord[2]);
	scene->camera.direction.x = ft_atod(split_vector[0]);
	scene->camera.direction.y = ft_atod(split_vector[1]);
	scene->camera.direction.z = ft_atod(split_vector[2]);
	scene->camera.fov = ft_atoi(split_line[3]);
	if (split_coord)
		ft_free_double_ptr(split_coord, ft_count_split_elements(split_coord));
	if (split_vector)
		ft_free_double_ptr(split_vector, ft_count_split_elements(split_vector));
	return (EXIT_SUCCESS);
}
