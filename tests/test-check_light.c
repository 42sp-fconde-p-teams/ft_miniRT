#include "./tests.h"
#include "../includes/miniRT.h"

int	should_succeed_for_valid_light_params(void)
{
	char	*line[] = {"L", "-40.0,50.0,0.0", "0.6", NULL};

	if (check_light(line) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_fail_for_lowercase_l(void)
{
	char	*line[] = {"l", "-40.0,50.0,0.0", "0.6", NULL};

	if (check_light(line) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_fail_for_identificator_with_more_than_one_char(void)
{
	char	*line[] = {"LL", "-40.0,50.0,0.0", "0.6", NULL};

	if (check_light(line) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_fail_for_brightness_bellow_zero(void)
{
	char	*line[] = {"L", "-40.0,50.0,0.0", "-0.0001", NULL};

	if (check_light(line) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_fail_for_brightness_above_one(void)
{
	char	*line[] = {"L", "-40.0,50.0,0.0", "1.0001", NULL};

	if (check_light(line) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_succeed_for_valid_light_params);
	RUN_TEST(should_fail_for_brightness_bellow_zero);
	RUN_TEST(should_fail_for_brightness_above_one);
	RUN_TEST(should_fail_for_lowercase_l);
	RUN_TEST(should_fail_for_identificator_with_more_than_one_char);
}
