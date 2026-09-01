#include "./tests.h"
#include "../includes/miniRT.h"

int	should_succeed_for_valid_plain_params(void)
{
	char	*line[] = {"pl", "0.0,0.0,-10.0", "0.0,1.0,0.0", "10,0,255", NULL};

	if (check_plain(line) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_fail_for_identifier_with_capital_char(void)
{
	char	*line[] = {"Pl", "0.0,0.0,-10.0", "0.0,1.0,0.0", "10,0,255", NULL};

	if (check_plain(line) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_fail_for_identifier_with_more_than_two_char(void)
{
	char	*line[] = {"pll", "0.0,0.0,-10.0", "0.0,1.0,0.0", "10,0,255", NULL};

	if (check_plain(line) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_succeed_for_valid_plain_params);
	RUN_TEST(should_fail_for_identifier_with_capital_char);
	RUN_TEST(should_fail_for_identifier_with_more_than_two_char);
}
