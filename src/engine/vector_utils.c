/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 05:50:10 by thfernan          #+#    #+#             */
/*   Updated: 2026/08/22 18:35:39 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	vec3_almost_equal(t_vec3 a, t_vec3 b)
{
	if (fabs(a.x - b.x) >= EPSILON)
		return (EXIT_SUCCESS);
	if (fabs(a.y - b.y) >= EPSILON)
		return (EXIT_SUCCESS);
	if (fabs(a.z - b.z) >= EPSILON)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
