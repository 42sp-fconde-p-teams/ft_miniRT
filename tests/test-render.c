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
	scene.camera.origin = vec3(0, 0, 0);
	scene.camera.direction = vec3(0, 0, 1);
	scene.camera.fov = 90;
	sphere.center = vec3(0, 0, 5);
	sphere.diameter = 2.0;
	sphere.color = (t_rgb){255, 0, 0};
	wrap = setup_wrap(&scene, &sphere);
	color = trace_pixel(&wrap, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	if (color.red == 255 && color.green == 0 && color.blue == 0)
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

int	main(void)
{
	RUN_TEST(should_trace_center_pixel_hit_sphere);
	RUN_TEST(should_trace_corner_pixel_return_black);
	RUN_TEST(should_return_black_when_sphere_behind);
	RUN_TEST(should_return_black_when_no_sphere);
	RUN_TEST(should_return_black_when_sphere_far);
}
