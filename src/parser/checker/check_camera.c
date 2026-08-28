/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 11:56:01 by fconde-p          #+#    #+#             */
/*   Updated: 2026/08/28 12:00:33 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

int	check_camera(char **line)
{
	if (ft_count_split_elements(line) != 4)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
