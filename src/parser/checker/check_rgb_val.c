/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb_val.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 00:02:55 by fconde-p          #+#    #+#             */
/*   Updated: 2026/08/27 13:00:49 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

int	check_rgb_val(char *rgb)
{
	char	**split_rgb;
	int		i;

	i = 0;
	split_rgb = ft_split(rgb, ',');
	while (rgb[i])
	{
		if (ft_isdigit(rgb[i]) == 0 && rgb[i] != ',')
			return (EXIT_FAILURE);
		i++;
	}
	if (ft_count_split_elements(split_rgb) != 3)
		return (EXIT_FAILURE);
	if (((ft_atoi(split_rgb[0]) < 0) || (ft_atoi(split_rgb[0]) > 255))
		|| ((ft_atoi(split_rgb[1]) < 0) || (ft_atoi(split_rgb[1]) > 255))
		|| ((ft_atoi(split_rgb[2]) < 0) || (ft_atoi(split_rgb[2]) > 255)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
