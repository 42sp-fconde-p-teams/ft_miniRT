/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 21:44:01 by fconde-p          #+#    #+#             */
/*   Updated: 2026/09/12 22:08:49 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

int	set_light(char **split_line, t_scene *scene)
{
	char	**split_coord;

	split_coord = NULL;
	split_coord = ft_split(split_line[1], ',');
	scene->light.coord_pol.x = ft_atod(split_coord[0]);
	scene->light.coord_pol.y = ft_atod(split_coord[1]);
	scene->light.coord_pol.z = ft_atod(split_coord[2]);
	scene->light.lighting = ft_atoi(split_line[2]);
	if (split_coord)
		ft_free_double_ptr(split_coord, ft_count_split_elements(split_coord));
	return (EXIT_SUCCESS);
}
