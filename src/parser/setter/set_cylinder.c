/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 21:44:01 by fconde-p          #+#    #+#             */
/*   Updated: 2026/09/13 08:56:50 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

static void	set_coord(char **coord, t_scene *scene)
{
	scene->cylinder.coord_center.x = ft_atod(coord[0]);
	scene->cylinder.coord_center.y = ft_atod(coord[1]);
	scene->cylinder.coord_center.z = ft_atod(coord[2]);
}

static void	set_vect(char **vect, t_scene *scene)
{
	scene->cylinder.vector.x = ft_atod(vect[0]);
	scene->cylinder.vector.y = ft_atod(vect[1]);
	scene->cylinder.vector.z = ft_atod(vect[2]);
}

static void	set_rgb(char **rgb, t_scene *scene)
{
	scene->cylinder.color.red = ft_atoi(rgb[0]);
	scene->cylinder.color.green = ft_atoi(rgb[1]);
	scene->cylinder.color.blue = ft_atoi(rgb[2]);
}

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
	set_coord(split_coord, scene);
	set_vect(split_vect, scene);
	scene->cylinder.diameter = ft_atod(split_line[3]);
	scene->cylinder.height = ft_atod(split_line[4]);
	scene->sphere.diameter = ft_atod(split_line[2]);
	set_rgb(split_rgb, scene);
	if (split_coord)
		ft_free_double_ptr(split_coord, ft_count_split_elements(split_coord));
	if (split_vect)
		ft_free_double_ptr(split_vect, ft_count_split_elements(split_vect));
	if (split_rgb)
		ft_free_double_ptr(split_rgb, ft_count_split_elements(split_rgb));
	return (EXIT_SUCCESS);
}
