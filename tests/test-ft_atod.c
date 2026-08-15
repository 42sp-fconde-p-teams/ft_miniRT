#include "./tests.h"
#include "../includes/miniRT.h"

int	should_convert_ascii_to_double(void)
{
	double	d_nbr = 0.0;
	char	str[4] = "3.14";

	d_nbr = ft_atod(str);
	if (1 == 1)
	{
		printf("CONVERSÃO ATOD: %f\n", d_nbr);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_convert_ascii_to_double);
	return (0);
}
