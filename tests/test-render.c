#include "./tests.h"
#include "../includes/miniRT.h"

static t_mlx_wrap	setup_wrap(t_scene *scene, t_sphere *sphere)
{
	t_mlx_wrap	wrap;

	ft_bzero(&wrap, sizeof(wrap));
	wrap.scene = scene;
	wrap.scene->sphere = sphere;
	return (wrap);
}

// Center pixel with sphere straight ahead should return sphere color.
int	should_trace_center_pixel_hit_sphere(void)
{
	t_scene		scene;
	t_sphere	sphere;
	t_mlx_wrap	wrap;
	t_rgb		color;

	ft_bzero(&scene, sizeof(scene));
	ft_bzero(&sphere, sizeof(sphere));
	scene.camera.origin = vec3(0, 0, 0);
	scene.camera.direction = vec3(0, 0, 1);
	scene.camera.fov = 90;
	scene.light.coord_pol = vec3(0, 5, 0);
	scene.light.lighting = 1.0;
	sphere.center = vec3(0, 0, 5);
	sphere.diameter = 2.0;
	sphere.color = (t_rgb){255, 0, 0};
	wrap = setup_wrap(&scene, &sphere);
	color = trace_pixel(&wrap, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	if (color.red > 0 && color.green == 0 && color.blue == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Corner pixel should miss the sphere and return black.
int	should_trace_corner_pixel_return_black(void)
{
	t_scene		scene;
	t_sphere	sphere;
	t_mlx_wrap	wrap;
	t_rgb		color;

	ft_bzero(&scene, sizeof(scene));
	ft_bzero(&sphere, sizeof(sphere));
	scene.camera.origin = vec3(0, 0, 0);
	scene.camera.direction = vec3(0, 0, 1);
	scene.camera.fov = 90;
	sphere.center = vec3(0, 0, 5);
	sphere.diameter = 2.0;
	sphere.color = (t_rgb){255, 0, 0};
	wrap = setup_wrap(&scene, &sphere);
	color = trace_pixel(&wrap, 0, 0);
	if (color.red == 0 && color.green == 0 && color.blue == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Sphere behind the camera: nothing visible, black everywhere.
int	should_return_black_when_sphere_behind(void)
{
	t_scene		scene;
	t_sphere	sphere;
	t_mlx_wrap	wrap;
	t_rgb		color;

	ft_bzero(&scene, sizeof(scene));
	ft_bzero(&sphere, sizeof(sphere));
	scene.camera.origin = vec3(0, 0, 0);
	scene.camera.direction = vec3(0, 0, 1);
	scene.camera.fov = 90;
	sphere.center = vec3(0, 0, -5);
	sphere.diameter = 2.0;
	sphere.color = (t_rgb){255, 0, 0};
	wrap = setup_wrap(&scene, &sphere);
	color = trace_pixel(&wrap, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	if (color.red == 0 && color.green == 0 && color.blue == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// No sphere in the scene: everything black.
int	should_return_black_when_no_sphere(void)
{
	t_scene		scene;
	t_mlx_wrap	wrap;
	t_rgb		color;

	ft_bzero(&scene, sizeof(scene));
	scene.camera.origin = vec3(0, 0, 0);
	scene.camera.direction = vec3(0, 0, 1);
	scene.camera.fov = 90;
	wrap.scene = &scene;
	color = trace_pixel(&wrap, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	if (color.red == 0 && color.green == 0 && color.blue == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Sphere too small / too far: pixel misses.
int	should_return_black_when_sphere_far(void)
{
	t_scene		scene;
	t_sphere	sphere;
	t_mlx_wrap	wrap;
	t_rgb		color;

	ft_bzero(&scene, sizeof(scene));
	ft_bzero(&sphere, sizeof(sphere));
	scene.camera.origin = vec3(0, 0, 0);
	scene.camera.direction = vec3(0, 0, 1);
	scene.camera.fov = 90;
	sphere.center = vec3(100, 0, 5);
	sphere.diameter = 1.0;
	sphere.color = (t_rgb){255, 0, 0};
	wrap = setup_wrap(&scene, &sphere);
	color = trace_pixel(&wrap, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	if (color.red == 0 && color.green == 0 && color.blue == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Two spheres on the ray's path: trace_pixel must pick the closest one (red),
// not the farther one (blue). The far sphere is placed first in the list
// to prove the render iterates through all of them.
int	should_hit_closest_sphere(void)
{
	t_scene		scene;
	t_sphere	far_sphere;
	t_sphere	close_sphere;
	t_mlx_wrap	wrap;
	t_rgb		color;

	ft_bzero(&scene, sizeof(scene));
	scene.camera.origin = vec3(0, 0, 0);
	scene.camera.direction = vec3(0, 0, 1);
	scene.camera.fov = 90;
	scene.light.coord_pol = vec3(0, 5, 0);
	scene.light.lighting = 1.0;
	// Esfera distante (z=10, azul) vem primeiro na lista.
	far_sphere.center = vec3(0, 0, 10);
	far_sphere.diameter = 2.0;
	far_sphere.color = (t_rgb){0, 0, 255};
	far_sphere.next = &close_sphere;
	// Esfera próxima (z=5, vermelha) vem depois.
	close_sphere.center = vec3(0, 0, 5);
	close_sphere.diameter = 2.0;
	close_sphere.color = (t_rgb){255, 0, 0};
	close_sphere.next = NULL;
	scene.sphere = &far_sphere;
	wrap = setup_wrap(&scene, &far_sphere);
	color = trace_pixel(&wrap, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	// Deve pegar a vermelha (mais próxima), não a azul (mais distante).
	if (color.red > 0 && color.green == 0 && color.blue == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	should_hit_middle_sphere_in_list_of_three(void)
{
	t_scene		scene;
	t_sphere	s1;
	t_sphere	s2;
	t_sphere	s3;
	t_mlx_wrap	wrap;
	t_rgb		color;

	ft_bzero(&scene, sizeof(scene));
	ft_bzero(&s1, sizeof(s1));
	ft_bzero(&s2, sizeof(s2));
	ft_bzero(&s3, sizeof(s3));
	scene.camera.origin = vec3(0, 0, 0);
	scene.camera.direction = vec3(0, 0, 1);
	scene.camera.fov = 90;
	scene.light.coord_pol = vec3(0, 5, 0);
	scene.light.lighting = 1.0;
	// Ordem na lista: s3 (z=10) -> s1 (z=3) -> s2 (z=5)
	// Mais próxima: s1 (z=3). Segunda: s2 (z=5). Mais distante: s3 (z=10).
	s3.center = vec3(0, 0, 10);
	s3.diameter = 2.0;
	s3.color = (t_rgb){0, 0, 255};   // azul
	s3.next = &s1;
	s1.center = vec3(0, 0, 3);
	s1.diameter = 2.0;
	s1.color = (t_rgb){255, 0, 0};   // vermelho
	s1.next = &s2;
	s2.center = vec3(0, 0, 5);
	s2.diameter = 2.0;
	s2.color = (t_rgb){0, 255, 0};   // verde
	s2.next = NULL;
	scene.sphere = &s3;
	wrap.scene = &scene;
	color = trace_pixel(&wrap, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	// Deve pegar o vermelho (s1, z=3), não o azul (s3) nem o verde (s2).
	if (color.red > 0 && color.green == 0 && color.blue == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_trace_center_pixel_hit_sphere);
	RUN_TEST(should_trace_corner_pixel_return_black);
	RUN_TEST(should_return_black_when_sphere_behind);
	RUN_TEST(should_return_black_when_no_sphere);
	RUN_TEST(should_return_black_when_sphere_far);
	RUN_TEST(should_hit_closest_sphere);
	RUN_TEST(should_hit_middle_sphere_in_list_of_three);
}
