/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 22:15:34 by thfernan          #+#    #+#             */
/*   Updated: 2026/11/21 16:05:15 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

// Iterates through the sphere list and updates hit with the closest
// intersection.
static void	check_spheres(t_ray ray, t_sphere *list, t_hit *hit)
{
	t_sphere	*current;
	double		t;

	current = list;
	while (current)
	{
		if (intersect_sphere(ray, *current, &t) == EXIT_SUCCESS
			&& t < hit->t)
		{
			hit->t = t;
			hit->type = TYPE_SPHERE;
			hit->object = current;
			hit->point = vec3_add(ray.origin, vec3_mul(ray.direction, t));
			hit->normal = vec3_normalize(
					vec3_sub(hit->point, current->center));
		}
		current = current->next;
	}
}

// Iterates through the plane list and updates hit with the closest 
// intersection.
static void	check_planes(t_ray ray, t_plain *list, t_hit *hit)
{
	t_plain	*current;
	double	t;

	current = list;
	while (current)
	{
		if (intersect_plane(ray, *current, &t) == EXIT_SUCCESS
			&& t < hit->t)
		{
			hit->t = t;
			hit->type = TYPE_PLANE;
			hit->object = current;
			hit->point = vec3_add(ray.origin, vec3_mul(ray.direction, t));
			hit->normal = vec3_normalize(current->vector);
		}
		current = current->next;
	}
}

// Returns the color of the object stored in the hit struct.
static t_rgb	get_object_color(t_hit *hit)
{
	t_rgb	color;

	color = (t_rgb){0, 0, 0};
	if (hit->type == TYPE_SPHERE)
		color = ((t_sphere *)hit->object)->color;
	else if (hit->type == TYPE_PLANE)
		color = ((t_plain *)hit->object)->color;
	else if (hit->type == TYPE_CYLINDER)
		color = ((t_cylinder *)hit->object)->color;
	return (color);
}

// Traces a single ray for pixel (x, y) and returns the resulting color.
t_rgb	trace_pixel(t_mlx_wrap *wrap, int x, int y)
{
	t_ray	ray_cam;
	t_hit	hit;
	t_rgb	color;

	hit.t = INFINITY;
	hit.type = -1;
	hit.object = NULL;
	ray_cam.origin = wrap->scene->camera.origin;
	ray_cam.direction = generate_ray_direction(wrap->scene->camera, x, y);
	check_spheres(ray_cam, wrap->scene->sphere, &hit);
	check_planes(ray_cam, wrap->scene->plain, &hit);
	if (hit.object == NULL)
		color = (t_rgb){0, 0, 0};
	else
		color = compute_lighting(wrap, get_object_color(&hit),
				hit.point, hit.normal);
	return (color);
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
