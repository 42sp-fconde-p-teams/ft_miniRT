#include "./tests.h"
#include "../includes/miniRT.h"

int	should_succeed_for_valid_sphere_params(void)
{
	char	*line[] = {"sp", "0.0,0.0,20.6", "12.6", "10,0,255", NULL};

	if (check_sphere(line) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_succeed_for_valid_sphere_params);
}
