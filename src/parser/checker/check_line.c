/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 22:02:16 by fconde-p          #+#    #+#             */
/*   Updated: 2026/08/20 22:41:21 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/miniRT.h"

int	check_line(char **split_line)
{
	int	i;

	i = 0;
	while (split_line[i])
	{
			printf("%s\n", split_line[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
