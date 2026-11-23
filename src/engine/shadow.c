/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 17:08:51 by thfernan          #+#    #+#             */
/*   Updated: 2026/11/22 20:43:47 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

// Computes the final color, taking shadows into account.
t_rgb	shade_hit(t_mlx_wrap *wrap, t_hit *hit)
{
	t_vec3	light_dir;
	double	distance;
	t_rgb	color;
	t_rgb	result;

	light_dir = vec3_sub(wrap->scene->light.coord_pol, hit->point);
	distance = vec3_length(light_dir);
	light_dir = vec3_normalize(light_dir);
	color = get_object_color(hit);
	if (is_in_shadow(wrap->scene, hit->point, light_dir, distance) == EXIT_SUCCESS)
		result = compute_ambient(wrap, color);
	else
		result = compute_lighting(wrap, color, hit->point, hit->normal);
	return (result);
}

// Checks if the point is blocked from the light by another object.
int	is_in_shadow(t_scene *scene, t_vec3 hit_point, t_vec3 light_dir,
		double distance_to_light)
{
	t_ray	shadow_ray;
	t_hit	shadow_hit;

	shadow_ray.origin = vec3_add(hit_point, vec3_mul(light_dir, EPSILON));
	shadow_ray.direction = light_dir;
	shadow_hit.t = distance_to_light;
	shadow_hit.object = NULL;
	check_spheres(shadow_ray, scene->sphere, &shadow_hit);
	check_planes(shadow_ray, scene->plain, &shadow_hit);
	check_cylinders(shadow_ray, scene->cylinder, &shadow_hit);
	if (shadow_hit.object != NULL)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
