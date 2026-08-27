/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ambience.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 23:33:47 by fconde-p          #+#    #+#             */
/*   Updated: 2026/08/27 15:30:10 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

int	check_ambience(char **line)
{
	if (ft_count_split_elements(line) != 3)
		return (EXIT_FAILURE);
	if	(ft_is_double(line[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_rgb_val(line[2]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
