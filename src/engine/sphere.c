/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 00:20:07 by thfernan          #+#    #+#             */
/*   Updated: 2026/09/26 16:12:37 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

// Solves |origin + t*direction - center|² = radius² for t.
// Result is a quadratic a*t² + b*t + c = 0.
static void	compute_quadratic(t_ray ray, t_sphere sphere, t_quadratic *quad)
{
	t_vec3	origin_to_center;
	double	radius;

	radius = sphere.diameter / 2.0;
	origin_to_center = vec3_sub(ray.origin, sphere.center);
	quad->a = vec3_dot(ray.direction, ray.direction);
	quad->b = 2.0 * vec3_dot(origin_to_center, ray.direction);
	quad->c = vec3_dot(origin_to_center, origin_to_center) - radius * radius;
	quad->discriminant = quad->b * quad->b - 4.0 * quad->a * quad->c;
}

int	intersect_sphere(t_ray ray, t_sphere sphere, double *distance)
{
	t_quadratic	quad;
	double		root;

	compute_quadratic(ray, sphere, &quad);
	if (quad.discriminant < 0.0)
		return (EXIT_FAILURE);
	root = (-quad.b - sqrt(quad.discriminant)) / (2.0 * quad.a);
	if (root < EPSILON)
		root = (-quad.b + sqrt(quad.discriminant)) / (2.0 * quad.a);
	if (root < EPSILON)
		return (EXIT_FAILURE);
	*distance = root;
	return (EXIT_SUCCESS);
}
