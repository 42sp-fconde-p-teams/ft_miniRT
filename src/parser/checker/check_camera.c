/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 11:56:01 by fconde-p          #+#    #+#             */
/*   Updated: 2026/09/13 16:42:12 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

static int	basic_check(char **line, t_scene *scene)
{
	if ((line[0][0] != 'C') || (ft_strlen(line[0]) != 1))
		return (EXIT_FAILURE);
	if (scene->camera.is_set == 1)
		return (EXIT_FAILURE);
	if (ft_count_split_elements(line) != 4)
		return (EXIT_FAILURE);
	if (check_coordinates(line[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_coordinates_in_range(0.0, 1.0, line[2]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_camera(char **line, t_scene *scene)
{
	char	**split_el;

	split_el = NULL;
	if (basic_check(line, scene) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	split_el = ft_split(line[2], ',');
	if (ft_atoi(line[3]) < 0 || ft_atoi(line[3]) > 180)
	{
		ft_free_array(split_el);
		return (EXIT_FAILURE);
	}
	ft_free_array(split_el);
	return (EXIT_SUCCESS);
}
