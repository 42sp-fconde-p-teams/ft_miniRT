/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 22:15:34 by thfernan          #+#    #+#             */
/*   Updated: 2026/11/20 19:55:11 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

// Traverses the sphere list and returns the closest one hit by the ray.
// Returns NULL if no sphere is hit.
static t_sphere	*find_closest_sphere(t_ray ray, t_sphere *list, double *t_hit)
{
	t_sphere	*closest;
	t_sphere	*current;
	double		t;
	double		closest_t;

	closest = NULL;
	closest_t = INFINITY;
	current = list;
	while (current)
	{
		if (intersect_sphere(ray, *current, &t) == EXIT_SUCCESS
			&& t < closest_t)
		{
			closest_t = t;
			closest = current;
		}
		current = current->next;
	}
	if (closest)
		*t_hit = closest_t;
	return (closest);
}

// Computes the final color for a ray that hit a sphere at distance t.
static t_rgb	shade_hit(t_mlx_wrap *wrap, t_ray ray, t_sphere *sphere,
		double t)
{
	t_vec3	hit_point;
	t_vec3	normal;

	hit_point = vec3_add(ray.origin, vec3_mul(ray.direction, t));
	normal = vec3_normalize(vec3_sub(hit_point, sphere->center));
	return (compute_lighting(wrap, sphere, hit_point, normal));
}

// Traces a single ray for pixel (x, y) and returns the resulting color.
t_rgb	trace_pixel(t_mlx_wrap *wrap, int x, int y)
{
	t_ray		ray_cam;
	t_sphere	*hit_sphere;
	double		t;

	ray_cam.origin = wrap->scene->camera.origin;
	ray_cam.direction = generate_ray_direction(wrap->scene->camera, x, y);
	hit_sphere = find_closest_sphere(ray_cam, wrap->scene->sphere, &t);
	if (!hit_sphere)
		return ((t_rgb){0, 0, 0});
	return (shade_hit(wrap, ray_cam, hit_sphere, t));
}

void	render(t_mlx_wrap *wrap)
{
	int		x;
	int		y;
	t_rgb	color;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			color = trace_pixel(wrap, x, y);
			ft_put_pixel(&wrap->img, x, y, color);
			x++;
		}
		y++;
	}
}
