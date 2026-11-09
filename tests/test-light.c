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

// Light perpendicular, ambient=0, camera aligned with reflection -> full red + specular white.
// To isolate diffuse, we move the camera so the specular is 0.
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
	// Câmera no eixo Z, a reflexão da luz (que vem de cima) não vai bater na câmera.
	scene.camera.origin = vec3(0, 0, 10); 
	wrap = setup_wrap(&scene, &light, &sphere);
	color = compute_lighting(&wrap, vec3(0, 0, 0), vec3(0, 1, 0));
	if (color.red == 255 && color.green == 0 && color.blue == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Light at 45 degrees: dot(N, L) ≈ 0.707. Camera off-axis -> specular = 0.
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
	scene.camera.origin = vec3(0, 0, 10);
	wrap = setup_wrap(&scene, &light, &sphere);
	color = compute_lighting(&wrap, vec3(0, 0, 0), vec3(0, 1, 0));
	if (color.red >= 179 && color.red <= 182)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Light behind surface: diffuse = 0, specular = 0.
int	should_return_black_when_light_behind(void)
{
	t_scene		scene;
	t_light		light;
	t_sphere	sphere;
	t_mlx_wrap	wrap;
	t_rgb		color;

	ft_bzero(&scene, sizeof(scene));
	light.coord_pol = vec3(0, -5, 0);
	light.lighting = 1.0;
	sphere.color = (t_rgb){255, 0, 0};
	scene.camera.origin = vec3(0, 0, 10);
	wrap = setup_wrap(&scene, &light, &sphere);
	color = compute_lighting(&wrap, vec3(0, 0, 0), vec3(0, 1, 0));
	if (color.red == 0 && color.green == 0 && color.blue == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Intensity 0.5. Camera off-axis to avoid specular.
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
	scene.camera.origin = vec3(0, 0, 10);
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
	scene.camera.origin = vec3(0, 0, 10);
	wrap = setup_wrap(&scene, &light, &sphere);
	color = compute_lighting(&wrap, vec3(0, 0, 0), vec3(0, 1, 0));
	if (color.red == 0 && color.green == 255 && color.blue == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Ambient alone, no light, no specular.
int	should_compute_ambient_light(void)
{
	t_scene		scene;
	t_light		light;
	t_sphere	sphere;
	t_mlx_wrap	wrap;
	t_rgb		color;

	ft_bzero(&scene, sizeof(scene));
	scene.ambience.lighting = 0.5;
	light.coord_pol = vec3(0, -5, 0);
	light.lighting = 1.0;
	sphere.color = (t_rgb){200, 100, 50};
	scene.camera.origin = vec3(0, 0, 10);
	wrap = setup_wrap(&scene, &light, &sphere);
	color = compute_lighting(&wrap, vec3(0, 0, 0), vec3(0, 1, 0));
	if (color.red == 100 && color.green == 50 && color.blue == 25)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Ambient + diffuse > 255 should clamp to 255.
int	should_limit_colors_to_255(void)
{
	t_scene		scene;
	t_light		light;
	t_sphere	sphere;
	t_mlx_wrap	wrap;
	t_rgb		color;

	ft_bzero(&scene, sizeof(scene));
	scene.ambience.lighting = 1.0;
	light.coord_pol = vec3(0, 5, 0);
	light.lighting = 1.0;
	sphere.color = (t_rgb){255, 0, 0};
	scene.camera.origin = vec3(0, 0, 10);
	wrap = setup_wrap(&scene, &light, &sphere);
	color = compute_lighting(&wrap, vec3(0, 0, 0), vec3(0, 1, 0));
	if (color.red == 255)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Specular highlight should appear when light, normal and view align.
int	should_add_specular_highlight(void)
{
	t_scene		scene;
	t_light		light;
	t_sphere	sphere;
	t_mlx_wrap	wrap;
	t_rgb		color;

	ft_bzero(&scene, sizeof(scene));
	// Luz e câmera posicionadas no mesmo ponto (acima do hit).
	// O reflexo vai bater direto na câmera -> especular máximo.
	light.coord_pol = vec3(0, 10, 0);
	light.lighting = 1.0;
	sphere.color = (t_rgb){255, 0, 0};
	scene.camera.origin = vec3(0, 10, 0);
	wrap = setup_wrap(&scene, &light, &sphere);
	color = compute_lighting(&wrap, vec3(0, 0, 0), vec3(0, 1, 0));
	
	// A cor final vai ter o vermelho da difusa (255) + o branco do especular (255).
	// O limit_rgb trava em 255. Então a cor final vai ser (255, 255, 255) - branco!
	if (color.red == 255 && color.green >= 250 && color.blue >= 250)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_compute_ambient_light);
	RUN_TEST(should_limit_colors_to_255);
	RUN_TEST(should_return_full_color_when_light_perpendicular);
	RUN_TEST(should_scale_color_by_cosine);
	RUN_TEST(should_return_black_when_light_behind);
	RUN_TEST(should_scale_by_light_intensity);
	RUN_TEST(should_only_light_sphere_color_channels);
	RUN_TEST(should_add_specular_highlight); // Novo teste
}
