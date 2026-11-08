/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 14:01:24 by thfernan          #+#    #+#             */
/*   Updated: 2026/11/08 18:40:37 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

// Computes the ambient contribution (no direction, affects all points)
static t_rgb	compute_ambient(t_mlx_wrap *wrap)
{
	t_rgb	result;
	double	ratio;

	ratio = wrap->scene->ambience.lighting;
	result.red = (int)(wrap->scene->sphere->color.red * ratio);
	result.green = (int)(wrap->scene->sphere->color.green * ratio);
	result.blue = (int)(wrap->scene->sphere->color.blue * ratio);
	return (result);
}

// Computes the diffuse lighting for a surface point.
// brightness = max(0, dot(N, L)).
static t_rgb	compute_diffuse(t_mlx_wrap *wrap, t_vec3 hit_point, t_vec3 normal)
{
	t_vec3	to_light;
	t_vec3	light_dir;
	double	diffuse;
	t_rgb	result;

	to_light = vec3_sub(wrap->scene->light.coord_pol, hit_point);
	light_dir = vec3_normalize(to_light);
	diffuse = vec3_dot(normal, light_dir);
	if (diffuse < 0.0)
		diffuse = 0.0;
	diffuse *= wrap->scene->light.lighting;
	result.red = (int)(wrap->scene->sphere->color.red * diffuse);
	result.green = (int)(wrap->scene->sphere->color.green * diffuse);
	result.blue = (int)(wrap->scene->sphere->color.blue * diffuse);
	return (result);
}

// Computes the specular highlight (Phong reflection model).
static t_rgb	compute_specular(t_mlx_wrap *wrap, t_vec3 hit_point,
		t_vec3 normal, t_vec3 light_dir)
{
	t_vec3	view_dir;
	t_vec3	reflect_dir;
	t_rgb	result;
	double	spec;
	double	intensity;

	view_dir = vec3_normalize(vec3_sub(wrap->scene->camera.origin, hit_point));
	reflect_dir = vec3_sub(
			vec3_mul(normal, 2.0 * vec3_dot(normal, light_dir)),
			light_dir);
	spec = vec3_dot(view_dir, reflect_dir);
	if (spec < 0.0)
		spec = 0.0;
	intensity = pow(spec, 50.0) * wrap->scene->light.lighting;
	result.red = limit_rgb((int)(255 * intensity));
	result.green = limit_rgb((int)(255 * intensity));
	result.blue = limit_rgb((int)(255 * intensity));
	return (result);
}

// Combines ambient and diffuse lighting
t_rgb	compute_lighting(t_mlx_wrap *wrap, t_vec3 hit_point, t_vec3 normal)
{
	t_vec3	light_dir;
	t_rgb	ambient;
	t_rgb	diffuse;
	t_rgb	specular;
	t_rgb	result;

	light_dir = vec3_normalize(
			vec3_sub(wrap->scene->light.coord_pol, hit_point));
	ambient = compute_ambient(wrap);
	diffuse = compute_diffuse(wrap, hit_point, normal);
	specular = compute_specular(wrap, hit_point, normal, light_dir);
	result = add_lights(ambient, diffuse, specular);
	return (result);
}
