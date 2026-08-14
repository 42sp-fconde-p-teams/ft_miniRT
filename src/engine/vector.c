/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 21:24:28 by thfernan          #+#    #+#             */
/*   Updated: 2026/08/14 00:18:38 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

// 3D vector with coordinates
t_vec3	vec3(double x, double y, double z)
{
	t_vec3	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

// shift points or to combine vectors.
t_vec3	vec3_add(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	return (result);
}

// to obtain the vector pointing from one point to another
t_vec3	vec3_sub(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	return (result);
}

// scales the vector (increases or decreases its length)
t_vec3	vec3_mul(t_vec3 v, double scale)
{
	t_vec3	result;

	result.x = v.x * scale;
	result.y = v.y * scale;
	result.z = v.z * scale;
	return (result);
}

int	vec3_almost_equal(t_vec3 a, t_vec3 b)
{
	if (fabs(a.x - b.x) >= EPSILON)
		return (0);
	if (fabs(a.y - b.y) >= EPSILON)
		return (0);
	if (fabs(a.z - b.z) >= EPSILON)
		return (0);
	return (1);
}
