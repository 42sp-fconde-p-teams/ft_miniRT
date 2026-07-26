/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 20:37:58 by fconde-p          #+#    #+#             */
/*   Updated: 2026/07/26 18:26:16 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	main(void)
{
	ft_printf("Success: %d\n", sample_return(EXIT_SUCCESS));
	ft_printf("Fail: %d\n", sample_return(EXIT_FAILURE));

	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	(void)mlx_win;
	mlx_loop(mlx);
	return (0);
}