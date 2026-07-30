/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 20:43:25 by fconde-p          #+#    #+#             */
/*   Updated: 2026/07/30 19:47:23 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../lib/libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../lib/minilibx/mlx.h"

# define KEY_ESC 65307

typedef struct s_mlx_wrap
{
	void	*mlx;
	void	*mlx_win;
}	t_mlx_wrap;

int	sample_return(int hard_result);
int	init_window(void);

#endif