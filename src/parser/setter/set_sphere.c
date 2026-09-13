/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 21:44:01 by fconde-p          #+#    #+#             */
/*   Updated: 2026/09/12 22:36:32 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

int	set_sphere(char **split_line, t_scene *scene)
{
	char	**split_coord;
	char	**split_rgb;

	split_coord = NULL;
	split_rgb = NULL;
	split_coord = ft_split(split_line[1], ',');
	split_rgb = ft_split(split_line[3], ',');
	scene->sphere.center.x = ft_atod(split_coord[0]);
	scene->sphere.center.y = ft_atod(split_coord[1]);
	scene->sphere.center.z = ft_atod(split_coord[2]);
	scene->sphere.diameter = ft_atod(split_line[2]);
	scene->sphere.color.red = ft_atod(split_rgb[0]);
	scene->sphere.color.green = ft_atod(split_rgb[1]);
	scene->sphere.color.blue = ft_atod(split_rgb[2]);
	if (split_coord)
		ft_free_double_ptr(split_coord, ft_count_split_elements(split_coord));
	if (split_rgb)
		ft_free_double_ptr(split_rgb, ft_count_split_elements(split_rgb));
	return (EXIT_SUCCESS);
}
