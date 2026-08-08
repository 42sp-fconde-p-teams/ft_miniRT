#include "./tests.h"
#include "../includes/miniRT.h"

int	should_accept_rt_valid_file(void)
{
	char	file_name[] = "test.rt";

	if (check_extention(file_name) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_fail_on_non_rt_file(void)
{
	char	file_name[] = "test.jpg";

	if (check_extention(file_name) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_accept_rt_file_with_another_rt_in_the_name(void)
{
	char	file_name[] = "test.rt.rt";

	if (check_extention(file_name) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_fail_if_filename_has_less_than_4_characters(void)
{
	char	file_name[] = ".rt";

	if (check_extention(file_name) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_accept_if_filename_has_at_least_4_characters(void)
{
	char	file_name[] = "a.rt";

	if (check_extention(file_name) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_accept_filename_with_space(void)
{
	char	file_name[] = "test space.rt";

	if (check_extention(file_name) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_fail_if_extention_is_not_in_the_end(void)
{
	char	file_name[] = "test.rttest";

	if (check_extention(file_name) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_accept_rt_valid_file);
	RUN_TEST(should_fail_on_non_rt_file);
	RUN_TEST(should_accept_rt_file_with_another_rt_in_the_name);
	RUN_TEST(should_fail_if_filename_has_less_than_4_characters);
	RUN_TEST(should_accept_if_filename_has_at_least_4_characters);
	RUN_TEST(should_accept_filename_with_space);
	RUN_TEST(should_fail_if_extention_is_not_in_the_end);
	return (0);
}
