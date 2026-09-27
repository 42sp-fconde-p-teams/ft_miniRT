/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 22:15:34 by thfernan          #+#    #+#             */
/*   Updated: 2026/09/27 10:12:32 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_rgb	trace_pixel(t_mlx_wrap *wrap, int x, int y)
{
	t_ray	ray_cam;
	t_vec3	direction;
	double	t;
	t_rgb	hit_color;

	direction = generate_ray_direction(wrap->scene->camera, x, y);
	ray_cam = ray(wrap->scene->camera.origin, direction);
	if (wrap->scene->sphere
		&& intersect_sphere(ray_cam, *wrap->scene->sphere, &t) == EXIT_SUCCESS)
		hit_color = wrap->scene->sphere->color;
	else
		hit_color = (t_rgb){0, 0, 0};
	return (hit_color);
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
