#include "./tests.h"
#include "../includes/miniRT.h"

int	should_succeed_for_valid_ambience_line(void)
{
	char	*line[] = {"A", "0.2", "150,150,150", NULL};

	if (check_ambience(line) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_succeed_for_valid_ambience_line);
}
