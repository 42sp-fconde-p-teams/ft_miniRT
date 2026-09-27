/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 20:01:33 by fconde-p          #+#    #+#             */
/*   Updated: 2026/09/27 10:44:20 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	ft_key_hook(int keycode, void *param)
{
	t_mlx_wrap	*mlx_wrap;

	mlx_wrap = (t_mlx_wrap *)param;
	if (keycode == KEY_ESC)
		printf("SAÍDA DE JANELA %d\n", close_window(mlx_wrap));
	return (EXIT_SUCCESS);
}

int	init_window(t_scene *scene, t_mlx_wrap *wrap)
{
	ft_bzero(wrap, sizeof(t_mlx_wrap));
	wrap->scene = scene;
	wrap->mlx = mlx_init();
	if (!wrap->mlx)
		return (EXIT_FAILURE);
	wrap->mlx_win = mlx_new_window(wrap->mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
	if (!wrap->mlx_win)
		return (EXIT_FAILURE);
	wrap->img.img_ptr = mlx_new_image(wrap->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!wrap->img.img_ptr)
		return (EXIT_FAILURE);
	wrap->img.addr = mlx_get_data_addr(wrap->img.img_ptr,
			&wrap->img.bits_per_pixel,
			&wrap->img.line_length,
			&wrap->img.endian);
	render(wrap);
	mlx_put_image_to_window(wrap->mlx, wrap->mlx_win,
		wrap->img.img_ptr, 0, 0);
	mlx_key_hook(wrap->mlx_win, ft_key_hook, wrap);
	mlx_hook(wrap->mlx_win, 17, 0, close_btn, wrap);
	return (EXIT_SUCCESS);
}
