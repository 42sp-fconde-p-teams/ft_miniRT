/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 20:43:25 by fconde-p          #+#    #+#             */
/*   Updated: 2026/08/09 21:44:39 by thfernan         ###   ########.fr       */
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
double	vec3_len(t_vec3 v);
t_vec3	vec3_norm(t_vec3 v);

// interseccion
double	intersect_sphere(t_ray ray, t_sphere sphere);

// cam ray
t_ray	camera_gen_ray(t_camera *cam, int x, int y);

// render
void	render(t_mlx_wrap *mlx, t_scene *scene);

// pixel put
void	my_mlx_pixel_put(t_img *img, int x, int y, t_vec3 color);

int		sample_return(int hard_result);
int		init_window(void);
int		close_window(t_mlx_wrap *mlx_wrap, void (*term_func)(int));
int		close_btn(t_mlx_wrap *mlx_wrap);
int		check_extention(char *file_name);

#endif