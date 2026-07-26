#include "./tests.h"
#include "../includes/miniRT.h"

int	test_sample_success(void)
{
	if (sample_return(EXIT_SUCCESS) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else if (sample_return(EXIT_SUCCESS) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	else
		return (-1);
}

int	test_sample_fail(void)
{
	if (sample_return(EXIT_FAILURE) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else if (sample_return(EXIT_FAILURE) != EXIT_FAILURE)
		return (EXIT_FAILURE);
	else
		return (-1);
}

int	main(void)
{
	RUN_TEST(test_sample_success);
	RUN_TEST(test_sample_fail);
	return (0);
}
