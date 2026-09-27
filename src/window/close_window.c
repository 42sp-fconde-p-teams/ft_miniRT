/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 20:15:11 by fconde-p          #+#    #+#             */
/*   Updated: 2026/09/27 10:31:35 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	cleanup(t_mlx_wrap *wrap)
{
	if (wrap->img.img_ptr)
		mlx_destroy_image(wrap->mlx, wrap->img.img_ptr);
	if (wrap->mlx_win)
		mlx_destroy_window(wrap->mlx, wrap->mlx_win);
	if (wrap->scene)
		free_scene(wrap->scene);
	if (wrap->mlx)
	{
		mlx_destroy_display(wrap->mlx);
		free(wrap->mlx);
	}
}

int	close_window(t_mlx_wrap *wrap)
{
	mlx_loop_end(wrap->mlx);
	return (EXIT_SUCCESS);
}

int	close_btn(void *param)
{
	close_window((t_mlx_wrap *)param);
	return (EXIT_SUCCESS);
}
