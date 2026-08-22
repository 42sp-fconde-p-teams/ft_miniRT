/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 17:55:54 by fconde-p          #+#    #+#             */
/*   Updated: 2026/08/22 18:07:22 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

int	check_identifier(char **line)
{
	if (line[0][0] == 'A')
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}