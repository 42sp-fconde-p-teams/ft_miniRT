/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 11:56:01 by fconde-p          #+#    #+#             */
/*   Updated: 2026/08/28 14:42:03 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

int	check_camera(char **line)
{
	char	**split_el;

	split_el = ft_split(line[2], ',');
	if (ft_count_split_elements(line) != 4)
	{
		ft_free_array(split_el);
		return (EXIT_FAILURE);
	}
	if (check_coordinates(line[1]) == EXIT_FAILURE)
	{
		ft_free_array(split_el);
		return (EXIT_FAILURE);
	}
	if (check_coordinates(line[2]) == EXIT_FAILURE)
	{
		ft_free_array(split_el);
		return (EXIT_FAILURE);
	}
	if (check_double_in_range(-1.0, 1.0, ft_atod(split_el[0])) == EXIT_FAILURE)
		{
			ft_free_array(split_el);
			return (EXIT_FAILURE);
		}
	ft_free_array(split_el);
	return (EXIT_SUCCESS);
}
