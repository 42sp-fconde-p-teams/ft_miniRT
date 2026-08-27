/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 14:38:11 by fconde-p          #+#    #+#             */
/*   Updated: 2026/08/27 16:07:07 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	ft_is_double(char *str)
{
	if (!ft_isdigit(*str))
		return (EXIT_FAILURE);
	if (!ft_strrchr(str, '.'))
		return (EXIT_FAILURE);
	while (*str)
	{
		if (ft_isdigit(*str))
			str++;
		else if (*str == '.')
		{
			str++;
			if (!*str)
				return (EXIT_FAILURE);
			while (*str)
			{
				if (ft_isdigit(*str))
					str++;
				else
					return (EXIT_FAILURE);
			}
		}
	}
	return (EXIT_SUCCESS);
}
