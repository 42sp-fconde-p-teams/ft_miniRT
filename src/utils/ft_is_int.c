/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 19:12:25 by fconde-p          #+#    #+#             */
/*   Updated: 2026/09/05 19:31:31 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	ft_is_int(char *str)
{
	if (*str == '-')
		str++;
	if (!ft_isdigit(*str))
		return (EXIT_FAILURE);
	while (*str)
	{
		if (ft_isdigit(*str))
			str++;
		else
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
