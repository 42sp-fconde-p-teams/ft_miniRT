/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 14:01:24 by thfernan          #+#    #+#             */
/*   Updated: 2026/10/10 18:10:58 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

// Computes the diffuse lighting for a surface point.
// brightness = max(0, dot(N, L)).
// Returns the sphere's color multiplied by the diffuse factor.
t_rgb	compute_lighting(t_mlx_wrap *wrap, t_vec3 hit_point, t_vec3 normal)
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
