/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ambience.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 23:33:47 by fconde-p          #+#    #+#             */
/*   Updated: 2026/08/24 23:39:27 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

int	check_ambience(char **line)
{
	if (ft_count_split_elements(line) == 3)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}