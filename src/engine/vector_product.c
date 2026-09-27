/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 05:51:50 by thfernan          #+#    #+#             */
/*   Updated: 2026/09/16 23:34:11 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

// Measures if two vectors point in the same direction, and how much.
double	vec3_dot(t_vec3 a, t_vec3 b)
{
	double	product;

	product = (a.x * b.x + a.y * b.y + a.z * b.z);
	return (product);
}

// Returns a vector perpendicular to both a and b. 
// Right-hand rule. Result is zero if a and b are parallel.
t_vec3	vec3_cross(t_vec3 a, t_vec3 b)
{
	t_vec3	cross;

	cross.x = a.y * b.z - a.z * b.y;
	cross.y = a.z * b.x - a.x * b.z;
	cross.z = a.x * b.y - a.y * b.x;
	return (cross);
}
