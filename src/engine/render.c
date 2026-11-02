/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 22:15:34 by thfernan          #+#    #+#             */
/*   Updated: 2026/10/10 18:12:56 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_rgb	trace_pixel(t_mlx_wrap *wrap, int x, int y)
{
	t_ray	ray_cam;
	t_vec3	hit_point;
	t_vec3	normal;
	double	t;
	t_rgb	color;

	ray_cam.origin = wrap->scene->camera.origin;
	ray_cam.direction = generate_ray_direction(wrap->scene->camera, x, y);
	if (wrap->scene->sphere
		&& intersect_sphere(ray_cam, *wrap->scene->sphere, &t) == EXIT_SUCCESS)
	{
		hit_point = vec3_add(ray_cam.origin, vec3_mul(ray_cam.direction, t));
		normal = vec3_normalize(
				vec3_sub(hit_point, wrap->scene->sphere->center));
		color = compute_lighting(wrap, hit_point, normal);
	}
	else
		color = (t_rgb){0, 0, 0};
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
