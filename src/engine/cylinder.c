/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 12:10:01 by thfernan          #+#    #+#             */
/*   Updated: 2026/11/22 12:37:18 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static void	compute_cyl_quadratic(t_ray ray, t_cylinder cyl, t_quadratic *q)
{
	t_vec3	axis;
	t_vec3	oc;
	t_vec3	d_perp;
	t_vec3	oc_perp;

	axis = vec3_normalize(cyl.vector);
	oc = vec3_sub(ray.origin, cyl.coord_center);
	d_perp = vec3_sub(ray.direction,
			vec3_mul(axis, vec3_dot(ray.direction, axis)));
	oc_perp = vec3_sub(oc, vec3_mul(axis, vec3_dot(oc, axis)));
	q->a = vec3_dot(d_perp, d_perp);
	q->b = 2.0 * vec3_dot(d_perp, oc_perp);
	q->c = vec3_dot(oc_perp, oc_perp) - pow(cyl.diameter / 2.0, 2.0);
	q->discriminant = q->b * q->b - 4.0 * q->a * q->c;
}

// Signed distance of the ray point at t along the cylinder axis.
static double	height_at(t_ray ray, t_cylinder cyl, double t)
{
	t_vec3	point;

	point = vec3_add(ray.origin, vec3_mul(ray.direction, t));
	return (vec3_dot(vec3_sub(point, cyl.coord_center),
			vec3_normalize(cyl.vector)));
}

static int	intersect_cyl_side(t_ray ray, t_cylinder cyl, double *distance)
{
	t_quadratic	quad;
	double		root;
	double		sq;

	compute_cyl_quadratic(ray, cyl, &quad);
	if (quad.a < EPSILON || quad.discriminant < 0.0)
		return (EXIT_FAILURE);
	sq = sqrt(quad.discriminant);
	root = (-quad.b - sq) / (2.0 * quad.a);
	if (root < EPSILON
		|| fabs(height_at(ray, cyl, root)) > cyl.height / 2.0)
		root = (-quad.b + sq) / (2.0 * quad.a);
	if (root < EPSILON
		|| fabs(height_at(ray, cyl, root)) > cyl.height / 2.0)
		return (EXIT_FAILURE);
	*distance = root;
	return (EXIT_SUCCESS);
}

// side = 1.0 for the top cap, -1.0 for the bottom cap.
static int	intersect_cap(t_ray ray, t_cylinder cyl, double side,
		double *distance)
{
	t_vec3	axis;
	t_vec3	center;
	t_vec3	point;
	double	denom;
	double	t;

	axis = vec3_normalize(cyl.vector);
	denom = vec3_dot(ray.direction, axis);
	if (fabs(denom) < EPSILON)
		return (EXIT_FAILURE);
	center = vec3_add(cyl.coord_center,
			vec3_mul(axis, side * cyl.height / 2.0));
	t = vec3_dot(vec3_sub(center, ray.origin), axis) / denom;
	if (t < EPSILON)
		return (EXIT_FAILURE);
	point = vec3_sub(vec3_add(ray.origin, vec3_mul(ray.direction, t)),
			center);
	if (vec3_dot(point, point) > pow(cyl.diameter / 2.0, 2.0))
		return (EXIT_FAILURE);
	*distance = t;
	return (EXIT_SUCCESS);
}

int	intersect_cylinder(t_ray ray, t_cylinder cyl, double *distance)
{
	double	best;
	double	t;

	best = INFINITY;
	if (intersect_cyl_side(ray, cyl, &t) == EXIT_SUCCESS && t < best)
		best = t;
	if (intersect_cap(ray, cyl, 1.0, &t) == EXIT_SUCCESS && t < best)
		best = t;
	if (intersect_cap(ray, cyl, -1.0, &t) == EXIT_SUCCESS && t < best)
		best = t;
	if (best == INFINITY)
		return (EXIT_FAILURE);
	*distance = best;
	return (EXIT_SUCCESS);
}
