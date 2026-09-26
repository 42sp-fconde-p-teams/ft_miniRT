#include "./tests.h"
#include "../includes/miniRT.h"

int	test_vec3_dot_basic(void)
{
	t_vec3	a = vec3(1, 4, 5);
	t_vec3	b = vec3(7, 8, 9);
	double	expected = 84.0;
	double	obtained = vec3_dot(a, b);

	if (fabs(expected - obtained) < EPSILON)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	test_vec3_dot_with_zero(void)
{
	t_vec3	a = vec3(2, 3, 4);
	t_vec3	zero = vec3(0, 0, 0);
	double	expected = 0.0;
	double	obtained = vec3_dot(a, zero);
	
	if (fabs(obtained - expected) < EPSILON)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	test_vec3_dot_perpendicular(void)
{
	t_vec3	a = vec3(1, 0, 0);
	t_vec3	b = vec3(0, 1, 0);
	double	expected = 0.0;
	double	obtained = vec3_dot(a, b);
	
	if (fabs(obtained - expected) < EPSILON)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	test_vec3_dot_negative(void)
{
	t_vec3	a = vec3(-1, -2, -3);
	t_vec3	b = vec3(4, 5, 6);
	double	expected = -32.0;
	double	obtained = vec3_dot(a, b);
	
	if (fabs(obtained - expected) < EPSILON)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	test_vec3_dot_decimal(void)
{
	t_vec3	a = vec3(1.5, 2.5, 3.5);
	t_vec3	b = vec3(0.5, 1.5, 2.5);
	double	expected = 13.25;
	double	obtained = vec3_dot(a, b);
	
	if (fabs(obtained - expected) < EPSILON)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	test_vec3_dot_opposite_direction(void)
{
	t_vec3	a = vec3(2, 3, 4);
	t_vec3	b = vec3(-2, -3, -4);
	double	expected = -29.0;
	double	obtained = vec3_dot(a, b);
	
	if (fabs(obtained - expected) < EPSILON)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	test_vec3_dot_same_vector(void)
{
	t_vec3	a = vec3(2, 3, 4);
	double	expected = 29.0;
	double	obtained = vec3_dot(a, a);
	
	if (fabs(obtained - expected) < EPSILON)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	should_cross_orthogonal_x_and_y(void)
{
	t_vec3	a = vec3(1, 0, 0);
	t_vec3	b = vec3(0, 1, 0);
	t_vec3	r = vec3_cross(a, b);

	if (vec3_almost_equal(r, vec3(0, 0, 1)) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	should_cross_orthogonal_y_and_x_invert_signal(void)
{
	t_vec3	a = vec3(0, 1, 0);
	t_vec3	b = vec3(1, 0, 0);
	t_vec3	r = vec3_cross(a, b);

	if (vec3_almost_equal(r, vec3(0, 0, -1)) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	should_cross_parallel_vectors_return_zero(void)
{
	t_vec3	a = vec3(1, 0, 0);
	t_vec3	b = vec3(2, 0, 0);
	t_vec3	r = vec3_cross(a, b);

	if (vec3_almost_equal(r, vec3(0, 0, 0)) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	should_cross_same_vector_return_zero(void)
{
	t_vec3	a = vec3(1, 2, 3);
	t_vec3	r = vec3_cross(a, a);

	if (vec3_almost_equal(r, vec3(0, 0, 0)) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	should_cross_generic_case(void)
{
	t_vec3	a = vec3(1, 2, 3);
	t_vec3	b = vec3(4, 5, 6);
	t_vec3	r = vec3_cross(a, b);

	// x = 2*6 - 3*5 = -3
	// y = 3*4 - 1*6 =  6
	// z = 1*5 - 2*4 = -3
	if (vec3_almost_equal(r, vec3(-3, 6, -3)) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	should_cross_with_negative_components(void)
{
	t_vec3	a = vec3(-1, 2, -3);
	t_vec3	b = vec3(4, -5, 6);
	t_vec3	r = vec3_cross(a, b);

	// x =  2*6  - (-3)*(-5) = 12 - 15 = -3
	// y = (-3)*4 - (-1)*6   = -12 + 6 = -6
	// z = (-1)*(-5) - 2*4   = 5 - 8   = -3
	if (vec3_almost_equal(r, vec3(-3, -6, -3)) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(test_vec3_dot_basic);
	RUN_TEST(test_vec3_dot_with_zero);
	RUN_TEST(test_vec3_dot_perpendicular);
	RUN_TEST(test_vec3_dot_negative);
	RUN_TEST(test_vec3_dot_decimal);
	RUN_TEST(test_vec3_dot_opposite_direction);
	RUN_TEST(test_vec3_dot_same_vector);
	RUN_TEST(should_cross_orthogonal_x_and_y);
	RUN_TEST(should_cross_orthogonal_y_and_x_invert_signal);
	RUN_TEST(should_cross_parallel_vectors_return_zero);
	RUN_TEST(should_cross_same_vector_return_zero);
	RUN_TEST(should_cross_generic_case);
	RUN_TEST(should_cross_with_negative_components);
	return (0);
}
