#include "./tests.h"
#include "../includes/miniRT.h"

int	should_pass_with_all_positive_values(void)
{
	char	coord[] = "50.0,0.0,2.0";

	if (check_coordinates(coord) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_pass_with_negative_x(void)
{
	char	coord[] = "-50.0,0.0,2.0";

	if (check_coordinates(coord) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_pass_with_negative_y(void)
{
	char	coord[] = "50.0,-10.0,2.0";

	if (check_coordinates(coord) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_pass_with_negative_z(void)
{
	char	coord[] = "50.0,0.0,-2.0";

	if (check_coordinates(coord) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_pass_with_all_negative_values(void)
{
	char	coord[] = "-50.0,-10.0,-2.0";

	if (check_coordinates(coord) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_pass_with_all_positive_values);
	RUN_TEST(should_pass_with_negative_x);
	RUN_TEST(should_pass_with_negative_y);
	RUN_TEST(should_pass_with_negative_z);
	RUN_TEST(should_pass_with_all_negative_values);
	return (0);
}