/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ambience.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 15:44:04 by fconde-p          #+#    #+#             */
/*   Updated: 2026/09/12 11:27:55 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

int	set_ambience(char **split_line, t_scene *scene)
{
	char	**split_rgb;

	split_rgb = NULL;
	split_rgb = ft_split(split_line[2], ',');
	scene->ambience.lighting = ft_atod(split_line[1]);
	scene->ambience.color.red = (ft_atoi(split_rgb[0]));
	scene->ambience.color.green = (ft_atoi(split_rgb[1]));
	scene->ambience.color.blue = (ft_atoi(split_rgb[2]));
	if (split_rgb)
		ft_free_double_ptr(split_rgb, ft_count_split_elements(split_rgb));
	return (EXIT_SUCCESS);
}
