/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 23:22:35 by fconde-p          #+#    #+#             */
/*   Updated: 2026/09/01 01:04:44 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

int	check_cylinder(char **line)
{
	if (line[0][0] != 'c' || line[0][1] != 'y'
		|| ft_strlen(line[0]) != 2)
		return (EXIT_FAILURE);
	if (ft_count_split_elements(line) != 6)
		return (EXIT_FAILURE);
	if (check_coordinates(line[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_coordinates_in_range(0.0, 1.0, line[2]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_is_double(line[4]) == EXIT_FAILURE
		|| ft_is_double(line[4]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_rgb_val(line[5]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
