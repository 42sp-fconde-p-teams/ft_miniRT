#include "./tests.h"
#include "../includes/miniRT.h"

int	test_vec3_add(void)
{
	t_vec3	a = vec3(1, 2, 3);
	t_vec3	b = vec3(4, 5, 6);
	t_vec3	result = vec3_add(a, b);

	if (result.x == 5 && result.y == 7 && result.z == 9)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	test_vec3_sub(void)
{
	t_vec3	a = vec3(1, 2, 3);
	t_vec3	b = vec3(4, 5, 6);
	t_vec3	result = vec3_sub(a, b);

	if (result.x == -3 && result.y == -3 && result.z == -3)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	test_vec3_mul(void)
{
	t_vec3	v = vec3(1, 3, 5);
	t_vec3	r = vec3_mul(v, 2);

	if (r.x == 2 && r.y == 6 && r.z == 10)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	test_vec3_constructor(void)
{
	t_vec3	v = vec3(7, -2, 0);

	if (v.x == 7 && v.y == -2 && v.z == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	test_vec3_add_zero(void)
{
	t_vec3	v = vec3(2, -3, 4);
	t_vec3	zero = vec3(0, 0, 0);
	t_vec3	r = vec3_add(v, zero);

	if (r.x == 2.0 && r.y == -3.0 && r.z == 4.0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	test_vec3_sub_zero(void)
{
	t_vec3	v = vec3(2, -3, 4);
	t_vec3	zero = vec3(0, 0, 0);
	t_vec3	r = vec3_sub(v, zero);

	if (r.x == 2.0 && r.y == -3.0 && r.z == 4.0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	test_vec3_mul_zero(void)
{
	t_vec3	v = vec3(2, -3, 4);
	t_vec3	r = vec3_mul(v, 0.0);

	if (r.x == 0.0 && r.y == 0.0 && r.z == 0.0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	test_vec3_add_opposite(void)
{
	t_vec3	a = vec3(1, -2, 3);
	t_vec3	b = vec3(-1, 2, -3);
	t_vec3	r = vec3_add(a, b);

	if (r.x == 0.0 && r.y == 0.0 && r.z == 0.0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	test_vec3_sub_negative(void)
{
	t_vec3	a = vec3(1, -2, 3);
	t_vec3	b = vec3(-4, 5, -6);
	t_vec3	r = vec3_sub(a, b);

	if (r.x == 5.0 && r.y == -7.0 && r.z == 9.0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	test_vec3_add_float(void)
{
	t_vec3	a = vec3(1.5, -2.3, 3.7);
	t_vec3	b = vec3(0.5, 1.3, -0.7);
	t_vec3	r = vec3_add(a, b);

	if (vec3_almost_equal(r, vec3(2.0, -1.0, 3.0)) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	test_vec3_sub_float(void)
{
	t_vec3	a = vec3(1.5, -2.3, 3.7);
	t_vec3	b = vec3(0.5, 1.3, -0.7);
	t_vec3	r = vec3_sub(a, b);

	if (vec3_almost_equal(r, vec3(1.0, -3.6, 4.4)) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	test_vec3_mul_float(void)
{
	t_vec3	v = vec3(2.0, -3.0, 4.0);
	t_vec3	r = vec3_mul(v, 0.5);

	if (r.x == 1.0 && r.y == -1.5 && r.z == 2.0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	test_vec3_mul_one(void)
{
	t_vec3	v = vec3(2, -3, 4);
	t_vec3	r = vec3_mul(v, 1.0);

	if (r.x == 2.0 && r.y == -3.0 && r.z == 4.0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	test_vec3_mul_minus_one(void)
{
	t_vec3	v = vec3(2, -3, 4);
	t_vec3	r = vec3_mul(v, -1.0);

	if (r.x == -2.0 && r.y == 3.0 && r.z == -4.0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	test_vec3_mul_fraction(void)
{
	t_vec3	v = vec3(2, -3, 4);
	t_vec3	r = vec3_mul(v, 0.5);

	if (r.x == 1.0 && r.y == -1.5 && r.z == 2.0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Length de (3, 4, 0) = 5 (triângulo)
int	should_compute_length_of_3_4_0(void)
{
	t_vec3	v = vec3(3, 4, 0);
	double	len = vec3_length(v);

	if (fabs(len - 5.0) < 1e-9)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Length de (1, 0, 0) = 1
int	should_compute_length_of_unit_x(void)
{
	t_vec3	v = vec3(1, 0, 0);
	double	len = vec3_length(v);

	if (fabs(len - 1.0) < 1e-9)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Length de (0, 0, 0) = 0
int	should_compute_length_of_zero_vector(void)
{
	t_vec3	v = vec3(0, 0, 0);
	double	len = vec3_length(v);

	if (fabs(len) < 1e-9)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Length de (1, 2, 2) = 3
int	should_compute_length_of_1_2_2(void)
{
	t_vec3	v = vec3(1, 2, 2);
	double	len = vec3_length(v);

	if (fabs(len - 3.0) < 1e-9)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(test_vec3_add);
	RUN_TEST(test_vec3_sub);
	RUN_TEST(test_vec3_mul);
	RUN_TEST(test_vec3_constructor);
	RUN_TEST(test_vec3_add_zero);
	RUN_TEST(test_vec3_sub_zero);
	RUN_TEST(test_vec3_mul_zero);
	RUN_TEST(test_vec3_add_opposite);
	RUN_TEST(test_vec3_sub_negative);
	RUN_TEST(test_vec3_add_float);
	RUN_TEST(test_vec3_sub_float);
	RUN_TEST(test_vec3_mul_float);
	RUN_TEST(test_vec3_mul_one);
	RUN_TEST(test_vec3_mul_minus_one);
	RUN_TEST(test_vec3_mul_fraction);
	RUN_TEST(should_compute_length_of_3_4_0);
	RUN_TEST(should_compute_length_of_unit_x);
	RUN_TEST(should_compute_length_of_zero_vector);
	RUN_TEST(should_compute_length_of_1_2_2);
	return (0);
}
