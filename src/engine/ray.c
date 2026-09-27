/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 23:43:22 by thfernan          #+#    #+#             */
/*   Updated: 2026/09/26 17:08:35 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_ray	ray(t_vec3 origin, t_vec3 direction)
{
	t_ray	r;

	r.origin = origin;
	r.direction = direction;
	return (r);
}

// Picks a "world up" that is NOT parallel to the camera forward.
// Parallel vectors would make the cross product zero and break the basis.
static t_vec3	pick_world_up(t_vec3 forward)
{
	t_vec3	world_up;

	world_up = vec3(0, 1, 0);
	if (fabs(forward.y) > 0.999)
		world_up = vec3(0, 0, 1);
	return (world_up);
}

// Builds the camera orthonormal basis: right, up, forward.
static void	compute_camera_basis(t_camera cam, t_camera_basis *basis)
{
	t_vec3	world_up;

	basis->forward = vec3_normalize(cam.direction);
	world_up = pick_world_up(basis->forward);
	basis->right = vec3_normalize(vec3_cross(basis->forward, world_up));
	basis->up = vec3_cross(basis->right, basis->forward);
}

// Generates a UNIT direction vector for the given screen pixel (x, y).
t_vec3	generate_ray_direction(t_camera cam, int x, int y)
{
	t_camera_basis	basis;
	t_vec3			direction;
	double			px;
	double			py;
	double			scale;

	compute_camera_basis(cam, &basis);
	scale = tan((double)cam.fov * M_PI / 360.0);
	px = (2.0 * (x + 0.5) / WIN_WIDTH - 1.0)
		* ((double)WIN_WIDTH / (double)WIN_HEIGHT) * scale;
	py = (1.0 - 2.0 * (y + 0.5) / WIN_HEIGHT) * scale;
	direction = vec3_add(
			vec3_add(vec3_mul(basis.right, px),
				vec3_mul(basis.up, py)),
			basis.forward);
	direction = vec3_normalize(direction);
	return (direction);
}
