/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 12:39:15 by thfernan          #+#    #+#             */
/*   Updated: 2026/11/22 12:39:37 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

// Cap normal if the point is on a cap, otherwise the radial normal.
static t_vec3	cylinder_normal(t_cylinder cyl, t_vec3 point)
{
	t_vec3	axis;
	t_vec3	rel;
	double	h;

	axis = vec3_normalize(cyl.vector);
	rel = vec3_sub(point, cyl.coord_center);
	h = vec3_dot(rel, axis);
	if (fabs(h) >= cyl.height / 2.0 - EPSILON)
	{
		if (h < 0.0)
			return (vec3_mul(axis, -1.0));
		return (axis);
	}
	return (vec3_normalize(vec3_sub(rel, vec3_mul(axis, h))));
}

void	check_cylinders(t_ray ray, t_cylinder *list, t_hit *hit)
{
	t_cylinder	*current;
	double		t;

	current = list;
	while (current)
	{
		if (intersect_cylinder(ray, *current, &t) == EXIT_SUCCESS
			&& t < hit->t)
		{
			hit->t = t;
			hit->type = TYPE_CYLINDER;
			hit->object = current;
			hit->point = vec3_add(ray.origin, vec3_mul(ray.direction, t));
			hit->normal = cylinder_normal(*current, hit->point);
		}
		current = current->next;
	}
}
