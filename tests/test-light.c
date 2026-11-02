#include "./tests.h"
#include "../includes/miniRT.h"

static t_mlx_wrap	setup_wrap(t_scene *scene, t_light *light,
						t_sphere *sphere)
{
	t_mlx_wrap	wrap;

	ft_bzero(&wrap, sizeof(wrap));
	scene->light = *light;
	scene->sphere = sphere;
	wrap.scene = scene;
	return (wrap);
}

// Light directly above the point: diffuse should be max (1.0 * intensity).
// Red sphere, white light at intensity 1.0 → full red.
int	should_return_full_color_when_light_perpendicular(void)
{
	t_scene		scene;
	t_light		light;
	t_sphere	sphere;
	t_mlx_wrap	wrap;
	t_rgb		color;

	ft_bzero(&scene, sizeof(scene));
	light.coord_pol = vec3(0, 5, 0);
	light.lighting = 1.0;
	sphere.color = (t_rgb){255, 0, 0};
	wrap = setup_wrap(&scene, &light, &sphere);
	color = compute_lighting(&wrap, vec3(0, 0, 0), vec3(0, 1, 0));
	if (color.red == 255 && color.green == 0 && color.blue == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Light at 45 degrees: dot(N, L) = cos(45°) ≈ 0.707
// 255 * 0.707 ≈ 180
int	should_scale_color_by_cosine(void)
{
	t_scene		scene;
	t_light		light;
	t_sphere	sphere;
	t_mlx_wrap	wrap;
	t_rgb		color;

	ft_bzero(&scene, sizeof(scene));
	light.coord_pol = vec3(5, 5, 0);
	light.lighting = 1.0;
	sphere.color = (t_rgb){255, 0, 0};
	wrap = setup_wrap(&scene, &light, &sphere);
	color = compute_lighting(&wrap, vec3(0, 0, 0), vec3(0, 1, 0));
	if (color.red >= 179 && color.red <= 182)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Light behind the surface: dot(N, L) < 0 → clamped to 0 → black.
int	should_return_black_when_light_behind(void)
{
	t_scene		scene;
	t_light		light;
	t_sphere	sphere;
	t_mlx_wrap	wrap;
	t_rgb		color;

	ft_bzero(&scene, sizeof(scene));
	light.coord_pol = vec3(0, -5, 0);   // luz embaixo
	light.lighting = 1.0;
	sphere.color = (t_rgb){255, 0, 0};
	wrap = setup_wrap(&scene, &light, &sphere);
	color = compute_lighting(&wrap, vec3(0, 0, 0), vec3(0, 1, 0));
	if (color.red == 0 && color.green == 0 && color.blue == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Intensity 0.5 should halve the diffuse contribution.
int	should_scale_by_light_intensity(void)
{
	t_scene		scene;
	t_light		light;
	t_sphere	sphere;
	t_mlx_wrap	wrap;
	t_rgb		color;

	ft_bzero(&scene, sizeof(scene));
	light.coord_pol = vec3(0, 5, 0);
	light.lighting = 0.5;
	sphere.color = (t_rgb){200, 100, 50};
	wrap = setup_wrap(&scene, &light, &sphere);
	color = compute_lighting(&wrap, vec3(0, 0, 0), vec3(0, 1, 0));
	if (color.red == 100 && color.green == 50 && color.blue == 25)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Green sphere: only green channel should be non-zero.
int	should_only_light_sphere_color_channels(void)
{
	t_scene		scene;
	t_light		light;
	t_sphere	sphere;
	t_mlx_wrap	wrap;
	t_rgb		color;

	ft_bzero(&scene, sizeof(scene));
	light.coord_pol = vec3(0, 5, 0);
	light.lighting = 1.0;
	sphere.color = (t_rgb){0, 255, 0};
	wrap = setup_wrap(&scene, &light, &sphere);
	color = compute_lighting(&wrap, vec3(0, 0, 0), vec3(0, 1, 0));
	if (color.red == 0 && color.green == 255 && color.blue == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_return_full_color_when_light_perpendicular);
	RUN_TEST(should_scale_color_by_cosine);
	RUN_TEST(should_return_black_when_light_behind);
	RUN_TEST(should_scale_by_light_intensity);
	RUN_TEST(should_only_light_sphere_color_channels);
}
