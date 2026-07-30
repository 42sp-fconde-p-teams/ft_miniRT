/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 20:01:33 by fconde-p          #+#    #+#             */
/*   Updated: 2026/07/29 21:00:38 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"


int	ft_key_hook(int keycode, t_mlx_wrap *mlx_wrap)
{
	// if (keycode == KEY_ESC)
	// 	mlx_destroy_window(mlx_wrap->mlx, mlx_wrap->mlx_win);
	ft_printf("BUTTON PRESSED");
	return (0);
}

int	init_window(void)
{
	t_mlx_wrap mlx_wrap;

	mlx_wrap.mlx = mlx_init();
	mlx_wrap.mlx_win = mlx_new_window(mlx_wrap.mlx, 800, 600, "FT_miniRT");
	// (void)mlx_win;
	mlx_key_hook(mlx_wrap.mlx_win, ft_key_hook, &mlx_wrap);
	mlx_loop(mlx_wrap.mlx);
	return (0);
}
