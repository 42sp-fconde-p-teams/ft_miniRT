#include "./tests.h"
#include "../includes/miniRT.h"

int	should_succeed_for_valid_cylinder_params(void)
{
	char	*line[] = {"cy", "50.0,0.0,20.6", "0.0,0.0,0.1", "14.2", "21.42",
		"10,0,255", NULL};

	if (check_cylinder(line) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_fail_for_identifier_with_capital_char(void)
{
	char	*line[] = {"Cy", "50.0,0.0,20.6", "0.0,0.0,0.1", "14.2", "21.42",
		"10,0,255", NULL};
	if (check_cylinder(line) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_fail_for_identifier_with_more_than_two_char(void)
{
	char	*line[] = {"ccy", "50.0,0.0,20.6", "0.0,0.0,0.1", "14.2", "21.42",
		"10,0,255", NULL};
	if (check_cylinder(line) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_succeed_for_valid_cylinder_params);
	RUN_TEST(should_fail_for_identifier_with_capital_char);
	RUN_TEST(should_fail_for_identifier_with_more_than_two_char);
}
