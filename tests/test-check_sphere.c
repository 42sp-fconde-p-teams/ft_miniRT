#include "./tests.h"
#include "../includes/miniRT.h"

int	should_succeed_for_valid_sphere_params(void)
{
	char	*line[] = {"sp", "0.0,0.0,20.6", "12.6", "10,0,255", NULL};

	if (check_sphere(line) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_fail_for_identifier_with_capital_char(void)
{
	char	*line[] = {"sP", "0.0,0.0,20.6", "12.6", "10,0,255", NULL};

	if (check_sphere(line) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_fail_for_identifier_with_more_than_two_char(void)
{
	char	*line[] = {"ssp", "0.0,0.0,20.6", "12.6", "10,0,255", NULL};

	if (check_sphere(line) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_succeed_for_valid_sphere_params);
	RUN_TEST(should_fail_for_identifier_with_capital_char);
	RUN_TEST(should_fail_for_identifier_with_more_than_two_char);
}
