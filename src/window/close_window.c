/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 20:15:11 by fconde-p          #+#    #+#             */
/*   Updated: 2026/08/01 18:49:45 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	close_window(t_mlx_wrap *mlx_wrap)
{
	if (mlx_wrap->mlx_win)
		mlx_destroy_window(mlx_wrap->mlx, mlx_wrap->mlx_win);
	if (mlx_wrap->mlx)
	{
		mlx_destroy_display(mlx_wrap->mlx);
		free(mlx_wrap->mlx);
	}
	exit(0);
	return (0);
}
