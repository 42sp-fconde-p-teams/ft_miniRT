#include "./tests.h"
#include "../includes/miniRT.h"

int	should_succeed_for_valid_camera_line(void)
{
	char	*line[] = {"A", "-50.0,0.0,20.0", "0.0,0.0,1.0", "70", NULL};

	if (check_camera(line) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_succeed_for_valid_camera_line);
}
