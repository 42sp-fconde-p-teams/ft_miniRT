/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 20:43:25 by fconde-p          #+#    #+#             */
/*   Updated: 2026/08/12 13:10:20 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../lib/libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "../lib/minilibx/mlx.h"

# define KEY_ESC 65307

typedef struct s_mlx_wrap
{
	void	*mlx;
	void	*mlx_win;
}	t_mlx_wrap;

int	sample_return(int hard_result);
int	init_window(void);
int	close_window(t_mlx_wrap *mlx_wrap, void (*term_func)(int));
int	close_btn(t_mlx_wrap *mlx_wrap);
int	check_extention(char *file_name);
int	read_file(char *file);

#endif