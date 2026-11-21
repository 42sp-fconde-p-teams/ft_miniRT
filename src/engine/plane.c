/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 09:45:17 by thfernan          #+#    #+#             */
/*   Updated: 2026/11/21 11:20:39 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	intersect_plane(t_ray ray, t_plain plane, double *distance)
{
	t_vec3	normal;
	double	denom;
	double	t;

	normal = vec3_normalize(plane.vector);
	denom = vec3_dot(ray.direction, normal);
	if (fabs(denom) < EPSILON)
		return (EXIT_FAILURE);
	t = vec3_dot(vec3_sub(plane.coord_point, ray.origin), normal) / denom;
	if (t < EPSILON)
		return (EXIT_FAILURE);
	*distance = t;
	return (EXIT_SUCCESS);
}
