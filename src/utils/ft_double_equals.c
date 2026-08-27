/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_equals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 12:34:01 by fconde-p          #+#    #+#             */
/*   Updated: 2026/08/27 12:35:59 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	ft_double_equals(double d_a, double d_b)
{
	if (fabs(d_a - d_b) >= EPSILON)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}