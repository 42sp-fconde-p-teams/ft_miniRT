/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_plain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 21:44:01 by fconde-p          #+#    #+#             */
/*   Updated: 2026/09/12 22:42:09 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

int	set_plain(char **split_line, t_scene *scene)
{
	char	**split_coord;
	char	**split_vect;
	char	**split_rgb;

	split_coord = NULL;
	split_vect = NULL;
	split_rgb = NULL;
	split_coord = ft_split(split_line[1], ',');
	split_vect = ft_split(split_line[2], ',');
	split_rgb = ft_split(split_line[3], ',');
	scene->plain.coord_point.x = ft_atod(split_coord[0]);
	scene->plain.coord_point.y = ft_atod(split_coord[1]);
	scene->plain.coord_point.z = ft_atod(split_coord[2]);
	scene->plain.vector.x = ft_atod(split_vect[0]);
	scene->plain.vector.y = ft_atod(split_vect[1]);
	scene->plain.vector.z = ft_atod(split_vect[2]);
	scene->plain.color.red = ft_atoi(split_rgb[0]);
	scene->plain.color.green = ft_atoi(split_rgb[1]);
	scene->plain.color.blue = ft_atoi(split_rgb[2]);
	if (split_coord)
		ft_free_double_ptr(split_coord, ft_count_split_elements(split_coord));
	if (split_vect)
		ft_free_double_ptr(split_vect, ft_count_split_elements(split_vect));
	if (split_rgb)
		ft_free_double_ptr(split_rgb, ft_count_split_elements(split_rgb));
	return (EXIT_SUCCESS);
}
