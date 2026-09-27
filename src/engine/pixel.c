/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 19:26:15 by thfernan          #+#    #+#             */
/*   Updated: 2026/09/26 19:27:11 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

// Writes an RGB color to the pixel at (x, y) in the image buffer.
void	ft_put_pixel(t_img *img, int x, int y, t_rgb color)
{
	char	*dst;

	dst = img->addr
		+ (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = (color.red << 16)
		| (color.green << 8)
		| color.blue;
}
