/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 21:44:01 by fconde-p          #+#    #+#             */
/*   Updated: 2026/09/17 18:49:25 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

static void	set_coord(char **split_line, t_cylinder *cylinder)
{
	char	**split_coord;

	split_coord = NULL;
	split_coord = ft_split(split_line[1], ',');
	cylinder->coord_center.x = ft_atod(split_coord[0]);
	cylinder->coord_center.y = ft_atod(split_coord[1]);
	cylinder->coord_center.z = ft_atod(split_coord[2]);
	ft_free_double_ptr(split_coord, ft_count_split_elements(split_coord));
}

static void	set_vect(char **split_line, t_cylinder *cylinder)
{
	char	**split_vect;

	split_vect = NULL;
	split_vect = ft_split(split_line[2], ',');
	cylinder->vector.x = ft_atod(split_vect[0]);
	cylinder->vector.y = ft_atod(split_vect[1]);
	cylinder->vector.z = ft_atod(split_vect[2]);
	ft_free_double_ptr(split_vect, ft_count_split_elements(split_vect));
}

static void	set_rgb(char **split_line, t_cylinder *cylinder)
{
	char	**split_rgb;

	split_rgb = NULL;
	split_rgb = ft_split(split_line[5], ',');
	cylinder->color.red = ft_atoi(split_rgb[0]);
	cylinder->color.green = ft_atoi(split_rgb[1]);
	cylinder->color.blue = ft_atoi(split_rgb[2]);
	ft_free_double_ptr(split_rgb, ft_count_split_elements(split_rgb));
}

static void	set_chain(t_scene *scene, t_cylinder *cylinder)
{
	t_cylinder	*temp_s;

	temp_s = NULL;
	if (!scene->cylinder)
		scene->cylinder = cylinder;
	else
	{
		temp_s = scene->cylinder;
		while (temp_s->next != NULL)
		{
			temp_s = temp_s->next;
		}
		temp_s->next = cylinder;
	}
}

int	set_cylinder(char **split_line, t_scene *scene)
{
	t_cylinder	*cylinder;

	cylinder = ft_calloc(sizeof(t_cylinder), 1);
	set_coord(split_line, cylinder);
	set_vect(split_line, cylinder);
	cylinder->diameter = ft_atod(split_line[3]);
	cylinder->height = ft_atod(split_line[4]);
	cylinder->diameter = ft_atod(split_line[2]);
	set_rgb(split_line, cylinder);
	set_chain(scene, cylinder);
	return (EXIT_SUCCESS);
}
