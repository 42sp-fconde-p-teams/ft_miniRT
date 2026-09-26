#include "./tests.h"
#include "../includes/miniRT.h"

int	should_create_ray_with_given_origin_and_direction(void)
{
	t_vec3	origin = vec3(1.0, 2.0, 3.0);
	t_vec3	direction = vec3(0.0, 0.0, 1.0);
	t_ray	r = ray(origin, direction);

	if (vec3_almost_equal(r.origin, origin) == EXIT_SUCCESS
		&& vec3_almost_equal(r.direction, direction) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	should_preserve_negative_components(void)
{
	t_vec3	origin = vec3(-1.5, -2.5, -3.5);
	t_vec3	direction = vec3(0.0, -1.0, 0.0);
	t_ray	r = ray(origin, direction);

	if (vec3_almost_equal(r.origin, vec3(-1.5, -2.5, -3.5)) == EXIT_SUCCESS
		&& vec3_almost_equal(r.direction, vec3(0.0, -1.0, 0.0)) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	should_preserve_float_values(void)
{
	t_vec3	origin = vec3(0.1, 0.2, 0.3);
	t_vec3	direction = vec3(0.5, 0.5, 0.7071);
	t_ray	r = ray(origin, direction);

	if (vec3_almost_equal(r.origin, origin) == EXIT_SUCCESS
		&& vec3_almost_equal(r.direction, direction) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_create_ray_with_given_origin_and_direction);
	RUN_TEST(should_preserve_negative_components);
	RUN_TEST(should_preserve_float_values);
}
