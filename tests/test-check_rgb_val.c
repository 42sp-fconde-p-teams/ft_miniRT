#include "./tests.h"
#include "../includes/miniRT.h"

int	should_pass_with_all_black(void)
{
	char	rgb[] = "0,0,0";

	if (check_rgb_val(rgb) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_pass_with_all_white(void)
{
	char	rgb[] = "255,255,255";

	if (check_rgb_val(rgb) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_fail_with_just_two_val(void)
{
	char	rgb[] = "150,250";

	if (check_rgb_val(rgb) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_fail_with_empty_last_val(void)
{
	char	rgb[] = "150,250, ";

	if (check_rgb_val(rgb) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_fail_with_void_last_val(void)
{
	char	rgb[] = "150,250,";

	if (check_rgb_val(rgb) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_pass_with_all_black);
	RUN_TEST(should_pass_with_all_white);
	RUN_TEST(should_fail_with_just_two_val);
	RUN_TEST(should_fail_with_empty_last_val);
	RUN_TEST(should_fail_with_void_last_val);
	return (0);
}