/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 05:50:10 by thfernan          #+#    #+#             */
/*   Updated: 2026/09/13 16:34:31 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	vec3_almost_equal(t_vec3 a, t_vec3 b)
{
	if (ft_double_equals(a.x, b.x) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_double_equals(a.y, b.y) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_double_equals(a.z, b.z) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
