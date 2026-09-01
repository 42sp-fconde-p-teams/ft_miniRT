/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coordinates_in_range.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 23:12:51 by fconde-p          #+#    #+#             */
/*   Updated: 2026/08/31 23:31:21 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

int	check_coordinates_in_range(double min, double max, char *coord)
{
	char	**split_coord;
	int		i;

	i = 0;
	split_coord = ft_split(coord, ',');
	if (ft_count_split_elements(split_coord) != 3)
	{
		ft_free_array(split_coord);
		return (EXIT_FAILURE);
	}
	while (split_coord[i])
	{
		if (ft_is_double(split_coord[i]) == EXIT_FAILURE
			|| check_double_in_range(min, max, ft_atod(split_coord[i]))
			== EXIT_FAILURE)
		{
			ft_free_array(split_coord);
			return (EXIT_FAILURE);
		}
		i++;
	}
	ft_free_array(split_coord);
	return (EXIT_SUCCESS);
}
