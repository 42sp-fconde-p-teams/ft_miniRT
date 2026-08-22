#include "./tests.h"
#include "../includes/miniRT.h"

int	should_succeed_for_identifier_A(void)
{
	char	*line[] = {"A", "0.2", NULL};

	if (check_identifier(line) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_succeed_for_identifier_C(void)
{
	char	*line[] = {"C", "0.2", NULL};

	if (check_identifier(line) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_succeed_for_identifier_L(void)
{
	char	*line[] = {"L", "0.2", NULL};

	if (check_identifier(line) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_succeed_for_identifier_sp(void)
{
	char	*line[] = {"sp", "0.2", NULL};

	if (check_identifier(line) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_succeed_for_identifier_pl(void)
{
	char	*line[] = {"pl", "0.2", NULL};

	if (check_identifier(line) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_succeed_for_identifier_cy(void)
{
	char	*line[] = {"cy", "0.2", NULL};

	if (check_identifier(line) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_succeed_for_identifier_A);
	RUN_TEST(should_succeed_for_identifier_C);
	RUN_TEST(should_succeed_for_identifier_L);
	RUN_TEST(should_succeed_for_identifier_sp);
	RUN_TEST(should_succeed_for_identifier_pl);
	RUN_TEST(should_succeed_for_identifier_cy);
	return (0);
}