/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 11:56:01 by fconde-p          #+#    #+#             */
/*   Updated: 2026/08/30 22:39:37 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

static int	basic_check(char **line)
{
	if ((line[0][0] != 'C') || (ft_strlen(line[0]) != 1))
		return (EXIT_FAILURE);
	if (ft_count_split_elements(line) != 4)
		return (EXIT_FAILURE);
	if (check_coordinates(line[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_coordinates(line[2]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_camera(char **line)
{
	char	**split_el;

	if (basic_check(line) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	split_el = ft_split(line[2], ',');
	if ((check_double_in_range(-1.0, 1.0, ft_atod(split_el[0])) == EXIT_FAILURE)
		|| (check_double_in_range(-1.0, 1.0, ft_atod(split_el[1]))
			== EXIT_FAILURE)
		|| (check_double_in_range(-1.0, 1.0, ft_atod(split_el[2]))
			== EXIT_FAILURE))
	{
		ft_free_array(split_el);
		return (EXIT_FAILURE);
	}
	if (ft_atoi(line[3]) < 0 || ft_atoi(line[3]) > 180)
	{
		ft_free_array(split_el);
		return (EXIT_FAILURE);
	}
	ft_free_array(split_el);
	return (EXIT_SUCCESS);
}
