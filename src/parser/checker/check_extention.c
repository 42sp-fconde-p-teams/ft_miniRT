/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extention.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 18:46:02 by fconde-p          #+#    #+#             */
/*   Updated: 2026/08/06 20:55:43 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	check_extention(char *file_name)
{
	int		ext_ending;
	char	*str;

	ext_ending = 0;
	str = NULL;
	ext_ending = ft_strlen(file_name) - 3;
	str = ft_substr(file_name, ext_ending, 3);
	if (str != NULL)
	{
		if (ft_strncmp(str, ".rt", 3) == 0)
		{
			free(str);
			return (EXIT_SUCCESS);
		}
		free(str);
		return (EXIT_FAILURE);
	}
	else
		return (EXIT_FAILURE);
}
