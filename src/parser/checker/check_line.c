/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 22:02:16 by fconde-p          #+#    #+#             */
/*   Updated: 2026/08/28 11:57:46 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

int	check_line(char **split_line)
{
	if (check_identifier(split_line) == EXIT_SUCCESS)
	{
		if ((split_line[0][0] == 'A')
			&& (check_ambience(split_line) == EXIT_SUCCESS))
		{
			printf("AMBIENCE OK\n");
			return (EXIT_SUCCESS);
		}
		else if ((split_line[0][0] == 'C')
			&& (check_camera(split_line) == EXIT_SUCCESS))
		{
			printf("CAMERA OK\n");
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_FAILURE);
}
