/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 20:01:33 by fconde-p          #+#    #+#             */
/*   Updated: 2026/08/02 11:24:29 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	ft_key_hook(int keycode, void *param)
{
	t_mlx_wrap	*mlx_wrap;

	mlx_wrap = (t_mlx_wrap *)param;
	if (keycode == KEY_ESC)
		close_window(mlx_wrap, exit);
	return (0);
}

int	init_window(void)
{
	t_mlx_wrap	mlx_wrap;

	mlx_wrap.mlx = mlx_init();
	mlx_wrap.mlx_win = mlx_new_window(mlx_wrap.mlx, 800, 600, "FT_miniRT");
	mlx_key_hook(mlx_wrap.mlx_win, ft_key_hook, &mlx_wrap);
	mlx_hook(mlx_wrap.mlx_win, 17, 0, close_btn, &mlx_wrap);
	mlx_loop(mlx_wrap.mlx);
	return (0);
}
