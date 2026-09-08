#include "./tests.h"
#include "../includes/miniRT.h"

int	should_succeed_for_valid_positive_int(void)
{
	char	str[] = "42";

	if (ft_is_int(str) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_succeed_for_all_zero_int(void)
{
	char	str[] = "00";

	if (ft_is_int(str) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_succeed_for_negative_int(void)
{
	char	str[] = "-10";

	if (ft_is_int(str) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_succeed_for_int_zero(void)
{
	char	str[] = "0";

	if (ft_is_int(str) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_fail_for_starting_with_dot(void)
{
	char	str[] = ".0";

	if (ft_is_int(str) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_fail_for_ending_with_dot(void)
{
	char	str[] = "0.";

	if (ft_is_int(str) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_fail_for_double(void)
{
	char	str[] = "4.2";

	if (ft_is_int(str) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_succeed_for_valid_positive_int);
	RUN_TEST(should_succeed_for_all_zero_int);
	RUN_TEST(should_succeed_for_negative_int);
	RUN_TEST(should_succeed_for_int_zero);
	RUN_TEST(should_fail_for_starting_with_dot);
	RUN_TEST(should_fail_for_ending_with_dot);
	RUN_TEST(should_fail_for_double);
}