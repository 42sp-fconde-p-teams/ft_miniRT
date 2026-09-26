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
// Center pixel, camera looking +Z: direction should be ~(0, 0, 1).
int	should_center_pixel_point_forward(void)
{
	t_camera	cam;
	t_vec3		dir;

	cam.origin = vec3(0, 0, 0);
	cam.direction = vec3(0, 0, 1);
	cam.fov = 90;
	dir = generate_ray_direction(cam, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	if (fabs(dir.x) < 0.01 && fabs(dir.y) < 0.01
		&& fabs(dir.z - 1.0) < 0.01)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Returned direction must be a unit vector (length = 1).
int	should_return_unit_vector(void)
{
	t_camera	cam;
	t_vec3		dir;
	double		len;

	cam.origin = vec3(0, 0, 0);
	cam.direction = vec3(0, 0, 1);
	cam.fov = 90;
	dir = generate_ray_direction(cam, 123, 456);
	len = vec3_length(dir);
	if (fabs(len - 1.0) < 1e-6)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Top-left pixel must point left (-x), up (+y), forward (+z).
int	should_top_left_pixel_point_up_left(void)
{
	t_camera	cam;
	t_vec3		dir;

	cam.origin = vec3(0, 0, 0);
	cam.direction = vec3(0, 0, 1);
	cam.fov = 90;
	dir = generate_ray_direction(cam, 0, 0);
	if (dir.x > 0.0 && dir.y > 0.0 && dir.z > 0.0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Bottom-right pixel must point right (+x), down (-y), forward (+z).
int	should_bottom_right_pixel_point_down_right(void)
{
	t_camera	cam;
	t_vec3		dir;

	cam.origin = vec3(0, 0, 0);
	cam.direction = vec3(0, 0, 1);
	cam.fov = 90;
	dir = generate_ray_direction(cam, WIN_WIDTH - 1, WIN_HEIGHT - 1);
	if (dir.x < 0.0 && dir.y < 0.0 && dir.z > 0.0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Wider FOV spreads rays more: same pixel, larger |x|.
int	should_wide_fov_spread_more(void)
{
	t_camera	wide;
	t_camera	tele;
	t_vec3		dir_wide;
	t_vec3		dir_tele;

	wide.origin = vec3(0, 0, 0);
	wide.direction = vec3(0, 0, 1);
	wide.fov = 120;
	tele.origin = vec3(0, 0, 0);
	tele.direction = vec3(0, 0, 1);
	tele.fov = 30;
	dir_wide = generate_ray_direction(wide, 0, WIN_HEIGHT / 2);
	dir_tele = generate_ray_direction(tele, 0, WIN_HEIGHT / 2);
	if (fabs(dir_wide.x) > fabs(dir_tele.x))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Camera looking along +X: must not degenerate.
int	should_handle_camera_looking_along_x(void)
{
	t_camera	cam;
	t_vec3		dir;
	double		len;

	cam.origin = vec3(0, 0, 0);
	cam.direction = vec3(1, 0, 0);
	cam.fov = 90;
	dir = generate_ray_direction(cam, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	len = vec3_length(dir);
	if (fabs(len - 1.0) < 1e-6 && dir.x > 0.9)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Camera looking straight up: triggers pick_world_up fallback.
int	should_handle_camera_looking_up(void)
{
	t_camera	cam;
	t_vec3		dir;
	double		len;

	cam.origin = vec3(0, 0, 0);
	cam.direction = vec3(0, 1, 0);
	cam.fov = 90;
	dir = generate_ray_direction(cam, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	len = vec3_length(dir);
	if (fabs(len - 1.0) < 1e-6 && dir.y > 0.9)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Camera looking straight down: also triggers fallback.
int	should_handle_camera_looking_down(void)
{
	t_camera	cam;
	t_vec3		dir;
	double		len;

	cam.origin = vec3(0, 0, 0);
	cam.direction = vec3(0, -1, 0);
	cam.fov = 90;
	dir = generate_ray_direction(cam, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	len = vec3_length(dir);
	if (fabs(len - 1.0) < 1e-6 && dir.y < -0.9)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Camera looking diagonal: no degeneracy, direction preserved.
int	should_handle_diagonal_direction(void)
{
	t_camera	cam;
	t_vec3		dir;
	t_vec3		expected;
	double		dot;

	cam.origin = vec3(0, 0, 0);
	cam.direction = vec3(1, 1, 1);
	cam.fov = 90;
	dir = generate_ray_direction(cam, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	expected = vec3_normalize(vec3(1, 1, 1));
	dot = vec3_dot(dir, expected);
	if (dot > 0.99)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_create_ray_with_given_origin_and_direction);
	RUN_TEST(should_preserve_negative_components);
	RUN_TEST(should_preserve_float_values);
	RUN_TEST(should_center_pixel_point_forward);
	RUN_TEST(should_return_unit_vector);
	RUN_TEST(should_top_left_pixel_point_up_left);
	RUN_TEST(should_bottom_right_pixel_point_down_right);
	RUN_TEST(should_wide_fov_spread_more);
	RUN_TEST(should_handle_camera_looking_along_x);
	RUN_TEST(should_handle_camera_looking_up);
	RUN_TEST(should_handle_camera_looking_down);
	RUN_TEST(should_handle_diagonal_direction);
}
