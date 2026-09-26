/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_plain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 21:44:01 by fconde-p          #+#    #+#             */
/*   Updated: 2026/09/16 21:24:10 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

static void	set_coord(char **coord, t_plain *plain)
{
	plain->coord_point.x = ft_atod(coord[0]);
	plain->coord_point.y = ft_atod(coord[1]);
	plain->coord_point.z = ft_atod(coord[2]);
}

static void	set_vect(char **vect, t_plain *plain)
{
	plain->vector.x = ft_atod(vect[0]);
	plain->vector.y = ft_atod(vect[1]);
	plain->vector.z = ft_atod(vect[2]);
}

static void	set_rgb(char **rgb, t_plain *plain)
{
	plain->color.red = ft_atoi(rgb[0]);
	plain->color.green = ft_atoi(rgb[1]);
	plain->color.blue = ft_atoi(rgb[2]);
}

static void	set_chain(t_scene *scene, t_plain *plain)
{
	t_plain	*temp_s;

	temp_s = NULL;
	if (!scene->plain)
		scene->plain = plain;
	else
	{
		temp_s = scene->plain;
		while (temp_s->next != NULL)
		{
			temp_s = temp_s->next;
		}
		temp_s->next = plain;
	}
}

int	set_plain(char **split_line, t_scene *scene)
{
	char	**split_coord;
	char	**split_vect;
	char	**split_rgb;
	t_plain	*plain;

	split_coord = NULL;
	split_vect = NULL;
	split_rgb = NULL;
	plain = ft_calloc(sizeof(t_plain), 1);
	split_coord = ft_split(split_line[1], ',');
	split_vect = ft_split(split_line[2], ',');
	split_rgb = ft_split(split_line[3], ',');
	set_coord(split_coord, plain);
	set_vect(split_vect, plain);
	set_rgb(split_rgb, plain);
	plain->next = NULL;
	set_chain(scene, plain);
	if (split_coord)
		ft_free_double_ptr(split_coord, ft_count_split_elements(split_coord));
	if (split_vect)
		ft_free_double_ptr(split_vect, ft_count_split_elements(split_vect));
	if (split_rgb)
		ft_free_double_ptr(split_rgb, ft_count_split_elements(split_rgb));
	return (EXIT_SUCCESS);
}
