#include "./tests.h"
#include "../includes/miniRT.h"

int	should_succeed_for_valid_camera_line(void)
{
	char	*line[] = {"C", "-50.0,0.0,20.0", "0.0,0.0,1.0", "70", NULL};

	if (check_camera(line) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_fail_for_lowercase_c(void)
{
	char	*line[] = {"c", "-50.0,0.0,20.0", "0.0,0.0,1.0", "70", NULL};

	if (check_camera(line) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_fail_when_identifier_more_than_one_char(void)
{
	char	*line[] = {"CC", "-50.0,0.0,20.0", "0.0,0.0,1.0", "70", NULL};

	if (check_camera(line) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_fail_for_orient_vec_above_one(void)
{
	char	*line[] = {"C", "-50.0,0.0,20.0", "0.0,0.0,1.1", "70", NULL};

	if (check_camera(line) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_fail_for_orient_vec_below_minus_one(void)
{
	char	*line[] = {"C", "-50.0,0.0,20.0", "0.0,-1.001,0.0", "70", NULL};

	if (check_camera(line) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_fail_for_FOV_above_180(void)
{
	char	*line[] = {"C", "-50.0,0.0,20.0", "0.0,-1.0,0.0", "181", NULL};

	if (check_camera(line) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_fail_for_FOV_below_zero(void)
{
	char	*line[] = {"C", "-50.0,0.0,20.0", "0.0,-1.0,0.0", "-1", NULL};

	if (check_camera(line) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_succeed_for_valid_camera_line);
	RUN_TEST(should_fail_for_orient_vec_above_one);
	RUN_TEST(should_fail_for_orient_vec_below_minus_one);
	RUN_TEST(should_fail_for_FOV_above_180);
	RUN_TEST(should_fail_for_FOV_below_zero);
	RUN_TEST(should_fail_for_lowercase_c);
	RUN_TEST(should_fail_when_identifier_more_than_one_char);
}
