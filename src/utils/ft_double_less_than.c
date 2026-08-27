/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_less_than.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 12:34:01 by fconde-p          #+#    #+#             */
/*   Updated: 2026/08/27 13:11:14 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	ft_double_less_than(double d_a, double d_b)
{
	if ((d_a - d_b) < -EPSILON)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
