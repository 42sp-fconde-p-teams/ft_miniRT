/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 17:55:54 by fconde-p          #+#    #+#             */
/*   Updated: 2026/08/22 18:38:22 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

int	check_identifier(char **line)
{
	if (line[0][0] == 'A' || line[0][0] == 'C' || line[0][0] == 'L')
		return (EXIT_SUCCESS);
	else if ((line[0][0] == 's' && line[0][1] == 'p')
		|| (line[0][0] == 'p' && line[0][1] == 'l')
		|| (line[0][0] == 'c' && line[0][1] == 'y'))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}