/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 05:51:50 by thfernan          #+#    #+#             */
/*   Updated: 2026/08/22 18:24:13 by thfernan         ###   ########.fr       */
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
