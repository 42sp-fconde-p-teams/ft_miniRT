/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 21:44:01 by fconde-p          #+#    #+#             */
/*   Updated: 2026/09/13 02:16:18 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

int	set_cylinder(char **split_line, t_scene *scene)
{
	char	**split_coord;
	char	**split_vect;
	char	**split_rgb;

	split_coord = NULL;
	split_vect = NULL;
	split_rgb = NULL;
	split_coord = ft_split(split_line[1], ',');
	split_vect = ft_split(split_line[2], ',');
	split_rgb = ft_split(split_line[5], ',');
	scene->cylinder.coord_center.x = ft_atod(split_coord[0]);
	scene->cylinder.coord_center.y = ft_atod(split_coord[1]);
	scene->cylinder.coord_center.z = ft_atod(split_coord[2]);
	scene->cylinder.vector.x = ft_atod(split_vect[0]);
	scene->cylinder.vector.y = ft_atod(split_vect[1]);
	scene->cylinder.vector.z = ft_atod(split_vect[2]);
	scene->cylinder.diameter = ft_atod(split_line[3]);
	scene->cylinder.height = ft_atod(split_line[4]);
	scene->sphere.diameter = ft_atod(split_line[2]);
	scene->cylinder.color.red = ft_atoi(split_rgb[0]);
	scene->cylinder.color.green = ft_atoi(split_rgb[1]);
	scene->cylinder.color.blue = ft_atoi(split_rgb[2]);
	if (split_coord)
		ft_free_double_ptr(split_coord, ft_count_split_elements(split_coord));
	if (split_vect)
		ft_free_double_ptr(split_vect, ft_count_split_elements(split_vect));
	if (split_rgb)
		ft_free_double_ptr(split_rgb, ft_count_split_elements(split_rgb));
	return (EXIT_SUCCESS);
}
