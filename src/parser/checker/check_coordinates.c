/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coordinates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 12:13:38 by fconde-p          #+#    #+#             */
/*   Updated: 2026/08/28 14:05:26 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

int	check_coordinates(char *coord)
{
	char	**split_coord;
	int		i;

	i = 0;
	split_coord = ft_split(coord, ',');
	while (split_coord[i])
	{
		if (ft_is_double(split_coord[i]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	if (ft_count_split_elements(split_coord) != 3)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
