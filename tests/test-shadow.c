#include "./tests.h"
#include "../includes/miniRT.h"

// An object between the point and the light should cast a shadow.
int	should_be_in_shadow_when_blocked(void)
{
	t_scene		scene;
	t_sphere	sphere;
	t_vec3		hit_point;
	t_vec3		light_dir;
	double		distance;

	ft_bzero(&scene, sizeof(scene));
	ft_bzero(&sphere, sizeof(sphere));
	hit_point = vec3(0, 0, 0);
	light_dir = vec3(1, 0, 0);
	distance = 10.0;
	sphere.center = vec3(5, 0, 0);
	sphere.diameter = 2.0;
	sphere.next = NULL;
	scene.sphere = &sphere;
	// A ray from (0,0,0) to (10,0,0) hits the sphere at x=5.
	if (is_in_shadow(&scene, hit_point, light_dir, distance) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Without objects in the scene, there is no shadow.
int	should_not_be_in_shadow_when_empty(void)
{
	t_scene		scene;
	t_vec3		hit_point;
	t_vec3		light_dir;
	double		distance;

	ft_bzero(&scene, sizeof(scene));
	hit_point = vec3(0, 0, 0);
	light_dir = vec3(1, 0, 0);
	distance = 10.0;
	scene.sphere = NULL;
	scene.plain = NULL;
	scene.cylinder = NULL;
	if (is_in_shadow(&scene, hit_point, light_dir, distance) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// An object behind the point (in the direction opposite to the light) does not cast a shadow.
int	should_not_be_in_shadow_when_object_is_behind(void)
{
	t_scene		scene;
	t_sphere	sphere;
	t_vec3		hit_point;
	t_vec3		light_dir;
	double		distance;

	ft_bzero(&scene, sizeof(scene));
	ft_bzero(&sphere, sizeof(sphere));
	hit_point = vec3(0, 0, 0);
	light_dir = vec3(1, 0, 0);
	distance = 10.0;
	// Sphere on the side opposite the light
	sphere.center = vec3(-5, 0, 0);
	sphere.diameter = 2.0;
	sphere.next = NULL;
	scene.sphere = &sphere;
	if (is_in_shadow(&scene, hit_point, light_dir, distance) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// An object beyond the light source does not cast a shadow (the light source is closer than the object).
int	should_not_be_in_shadow_when_object_is_beyond_light(void)
{
	t_scene		scene;
	t_sphere	sphere;
	t_vec3		hit_point;
	t_vec3		light_dir;
	double		distance;

	ft_bzero(&scene, sizeof(scene));
	ft_bzero(&sphere, sizeof(sphere));
	hit_point = vec3(0, 0, 0);
	light_dir = vec3(1, 0, 0);
	distance = 5.0;
	sphere.center = vec3(10, 0, 0);
	sphere.diameter = 2.0;
	sphere.next = NULL;
	scene.sphere = &sphere;
	// The shadow ray extends up to t=5, so it shouldn't hit the sphere at t=10.
	if (is_in_shadow(&scene, hit_point, light_dir, distance) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_be_in_shadow_when_blocked);
	RUN_TEST(should_not_be_in_shadow_when_empty);
	RUN_TEST(should_not_be_in_shadow_when_object_is_behind);
	RUN_TEST(should_not_be_in_shadow_when_object_is_beyond_light);
}
