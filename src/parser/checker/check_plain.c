/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_plain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 21:51:37 by fconde-p          #+#    #+#             */
/*   Updated: 2026/08/31 22:59:45 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

int	check_plain(char **line)
{
	char	**split_el;

	split_el = NULL;
	if (line[0][0] != 'p' || line[0][1] != 'l'
		|| ft_strlen(line[0]) != 2)
		return (EXIT_FAILURE);
	if (ft_count_split_elements(line) != 4)
		return (EXIT_FAILURE);
	if (check_coordinates(line[1]) == EXIT_FAILURE)
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
	ft_free_array(split_el);
	if (check_rgb_val(line[3]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
