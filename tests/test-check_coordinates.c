#include "./tests.h"
#include "../includes/miniRT.h"

int	should_pass_with_all_positive_double_values(void)
{
	char	coord[] = "50.0,0.0,2.0";

	if (check_coordinates(coord) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_pass_with_all_positive_int_values(void)
{
	char	coord[] = "50,0,2";

	if (check_coordinates(coord) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_pass_with_negative_double_x(void)
{
	char	coord[] = "-50.0,0.0,2.0";

	if (check_coordinates(coord) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_pass_with_negative_int_x(void)
{
	char	coord[] = "-50,0,2";

	if (check_coordinates(coord) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_pass_with_negative_double_y(void)
{
	char	coord[] = "50.0,-10.0,2.0";

	if (check_coordinates(coord) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_pass_with_negative_int_y(void)
{
	char	coord[] = "50,-10,2";

	if (check_coordinates(coord) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_pass_with_negative_double_z(void)
{
	char	coord[] = "50.0,0.0,-2.0";

	if (check_coordinates(coord) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_pass_with_negative_int_z(void)
{
	char	coord[] = "50,0,-2";

	if (check_coordinates(coord) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_pass_with_all_negative_double_values(void)
{
	char	coord[] = "-50.0,-10.0,-2.0";

	if (check_coordinates(coord) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_pass_with_all_negative_int_values(void)
{
	char	coord[] = "-50,-10,-2";

	if (check_coordinates(coord) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_pass_with_mixed_double_and_int_values(void)
{
	char	coord[] = "-50.0,10,-2";

	if (check_coordinates(coord) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_fail_for_alpha_values(void)
{
	char	coord[] = "-50.0,a,-2";

	if (check_coordinates(coord) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_pass_with_all_positive_double_values);
	RUN_TEST(should_pass_with_all_positive_int_values);
	RUN_TEST(should_pass_with_negative_double_x);
	RUN_TEST(should_pass_with_negative_int_x);
	RUN_TEST(should_pass_with_negative_double_y);
	RUN_TEST(should_pass_with_negative_int_y);
	RUN_TEST(should_pass_with_negative_double_z);
	RUN_TEST(should_pass_with_negative_int_z);
	RUN_TEST(should_pass_with_all_negative_double_values);
	RUN_TEST(should_pass_with_all_negative_int_values);
	RUN_TEST(should_pass_with_mixed_double_and_int_values);
	RUN_TEST(should_fail_for_alpha_values);
	return (0);
}