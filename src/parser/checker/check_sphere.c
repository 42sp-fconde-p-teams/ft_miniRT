/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 21:08:25 by fconde-p          #+#    #+#             */
/*   Updated: 2026/08/30 22:46:43 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

int	check_sphere(char **line)
{
	if (line[0][0] != 's' || line[0][1] != 'p'
		|| ft_strlen(line[0]) != 2)
		return (EXIT_FAILURE);
	if (ft_count_split_elements(line) != 4)
		return (EXIT_FAILURE);
	if (check_coordinates(line[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_is_double(line[2]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_rgb_val(line[3]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
