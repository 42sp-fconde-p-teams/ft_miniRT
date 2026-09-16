/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 21:44:01 by fconde-p          #+#    #+#             */
/*   Updated: 2026/09/15 22:27:59 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

static void	set_chain(t_scene *scene, t_sphere *sphere)
{
	// t_sphere	*head_s;
	t_sphere	*temp_s;

	// head_s = NULL;
	temp_s = NULL;
	if (!scene->sphere)
		scene->sphere = sphere;
	else
	{
		// head_s = scene->sphere;
		temp_s = scene->sphere;
		while (temp_s != NULL)
		{
			temp_s = temp_s->next;
		}
		temp_s = sphere;
	}
}

int	set_sphere(char **split_line, t_scene *scene)
{
	char		**split_coord;
	char		**split_rgb;
	t_sphere	*sphere;

	split_coord = NULL;
	split_rgb = NULL;
	split_coord = ft_split(split_line[1], ',');
	split_rgb = ft_split(split_line[3], ',');
	sphere = ft_calloc(sizeof(t_sphere), 1);
	sphere->center.x = ft_atod(split_coord[0]);
	sphere->center.y = ft_atod(split_coord[1]);
	sphere->center.z = ft_atod(split_coord[2]);
	sphere->diameter = ft_atod(split_line[2]);
	sphere->color.red = ft_atoi(split_rgb[0]);
	sphere->color.green = ft_atoi(split_rgb[1]);
	sphere->color.blue = ft_atoi(split_rgb[2]);
	sphere->next = NULL;
	set_chain(scene, sphere);
	if (split_coord)
		ft_free_double_ptr(split_coord, ft_count_split_elements(split_coord));
	if (split_rgb)
		ft_free_double_ptr(split_rgb, ft_count_split_elements(split_rgb));
	return (EXIT_SUCCESS);
}
