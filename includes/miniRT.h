/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 20:43:25 by fconde-p          #+#    #+#             */
/*   Updated: 2026/08/27 12:36:44 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../lib/libft/libft.h"
# include "../lib/minilibx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define KEY_ESC 65307
# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define FOV_MIN 0
# define FOV_MAX 180
# define EPSILON 1e-9

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}	t_ray;

typedef struct s_sphere
{
	t_vec3	center;
	double	radius;
	t_vec3	color;
}	t_sphere;

typedef struct s_camera
{
	t_vec3	origin;
	t_vec3	direction;
	int		fov;
}	t_camera;

typedef struct s_scene
{
	t_camera	camera;
	t_sphere	sphere;
}	t_scene;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;
typedef struct s_mlx_wrap
{
	void	*mlx;
	void	*mlx_win;
}	t_mlx_wrap;

// math of vectors
t_vec3	vec3(double x, double y, double z);
t_vec3	vec3_add(t_vec3 a, t_vec3 b);
t_vec3	vec3_sub(t_vec3 a, t_vec3 b);
t_vec3	vec3_mul(t_vec3 v, double t);
double	vec3_dot(t_vec3 a, t_vec3 b);
int		vec3_almost_equal(t_vec3 a, t_vec3 b);

int		sample_return(int hard_result);
int		init_window(void);
int		close_window(t_mlx_wrap *mlx_wrap, void (*term_func)(int));
int		close_btn(t_mlx_wrap *mlx_wrap);
int		check_extention(char *file_name);
int		read_file(char *file);
double	ft_atod(char *nptr);
size_t	ft_count_split_elements(char **splited);
int		check_line(char **split_line);
int		check_identifier(char **line);
int		check_ambience(char **line);
int		check_rgb_val(char *rgb);
int		ft_double_equals(double d_a, double d_b);

#endif