#include "./tests.h"
#include "../includes/miniRT.h"

int	should_succeed_for_valid_positive_double(void)
{
	char	str[] = "4.2";

	if (ft_is_double(str) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_succeed_for_all_zero_double(void)
{
	char	str[] = "0.0";

	if (ft_is_double(str) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_succeed_for_int_zero(void)
{
	char	str[] = "0";

	if (ft_is_double(str) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_succeed_for_valid_positive_double);
	RUN_TEST(should_succeed_for_all_zero_double);
	RUN_TEST(should_succeed_for_int_zero);
}