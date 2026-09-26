/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 05:50:10 by thfernan          #+#    #+#             */
/*   Updated: 2026/09/26 16:58:00 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	vec3_almost_equal(t_vec3 a, t_vec3 b)
{
	if (ft_double_equals(a.x, b.x) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_double_equals(a.y, b.y) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_double_equals(a.z, b.z) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

// Returns a unit vector (length = 1) pointing in the same direction.
// Returns (0, 0, 0) if the input has zero length to avoid division by zero.
t_vec3	vec3_normalize(t_vec3 v)
{
	double	length;
	t_vec3	unit;

	length = vec3_length(v);
	if (length < EPSILON)
	{
		unit.x = 0;
		unit.y = 0;
		unit.z = 0;
		return (unit);
	}
	unit.x = v.x / length;
	unit.y = v.y / length;
	unit.z = v.z / length;
	return (unit);
}
