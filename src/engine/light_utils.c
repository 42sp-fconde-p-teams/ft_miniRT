/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 18:19:37 by thfernan          #+#    #+#             */
/*   Updated: 2026/11/08 18:21:24 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	limit_rgb(int value)
{
	if (value < 0)
		return (0);
	if (value > 255)
		return (255);
	return (value);
}

t_rgb	add_lights(t_rgb a, t_rgb d, t_rgb s)
{
	t_rgb	result;

	result.red = limit_rgb(a.red + d.red + s.red);
	result.green = limit_rgb(a.green + d.green + s.green);
	result.blue = limit_rgb(a.blue + d.blue + s.blue);
	return (result);
}
