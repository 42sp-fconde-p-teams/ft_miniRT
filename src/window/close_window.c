/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 20:15:11 by fconde-p          #+#    #+#             */
/*   Updated: 2026/08/02 11:27:10 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	close_window(t_mlx_wrap *mlx_wrap, void (*term_func)(int))
{
	if (mlx_wrap->mlx_win)
	{
		mlx_destroy_window(mlx_wrap->mlx, mlx_wrap->mlx_win);
		mlx_wrap->mlx_win = NULL;
	}
	if (mlx_wrap->mlx)
	{
		mlx_destroy_display(mlx_wrap->mlx);
		free(mlx_wrap->mlx);
		mlx_wrap->mlx = NULL;
	}
	if (term_func)
		term_func(0);
	return (0);
}

int	close_btn(t_mlx_wrap *mlx_wrap)
{
	close_window(mlx_wrap, exit);
	return (0);
}
