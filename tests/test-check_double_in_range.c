#include "./tests.h"
#include "../includes/miniRT.h"

int	shoud_succeed_for_number_in_range(void)
{
	double	min = 0.0;
	double	max = 1.0;
	double	num = 0.5;

	if (check_double_in_range(min, max, num) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	shoud_succeed_for_number_in_min_value(void)
{
	double	min = 0.0;
	double	max = 1.0;
	double	num = 0.0;

	if (check_double_in_range(min, max, num) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	shoud_succeed_for_number_in_max_value(void)
{
	double	min = 0.0;
	double	max = 1.0;
	double	num = 1.0;

	if (check_double_in_range(min, max, num) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	shoud_fail_for_num_below_min_val(void)
{
	double	min = 0.0;
	double	max = 1.0;
	double	num = -0.001;

	if (check_double_in_range(min, max, num) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	shoud_fail_for_num_above_max_val(void)
{
	double	min = 0.0;
	double	max = 1.0;
	double	num = 1.001;

	if (check_double_in_range(min, max, num) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(shoud_succeed_for_number_in_range);
	RUN_TEST(shoud_succeed_for_number_in_min_value);
	RUN_TEST(shoud_succeed_for_number_in_max_value);
	RUN_TEST(shoud_fail_for_num_below_min_val);
	RUN_TEST(shoud_fail_for_num_above_max_val);
}