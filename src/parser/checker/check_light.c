/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 19:42:50 by fconde-p          #+#    #+#             */
/*   Updated: 2026/08/30 19:51:34 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

int	check_light(char **line)
{
	if (ft_count_split_elements(line) != 3)
		return (EXIT_FAILURE);
	if (check_coordinates(line[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_double_in_range(0.0, 1.0, ft_atod(line[2])) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
