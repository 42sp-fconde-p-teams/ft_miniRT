#include "./tests.h"
#include "../includes/miniRT.h"

int	should_convert_positive_nbr_string_to_double(void)
{
	double	d_nbr = 0.0;
	char	str[4] = "3.14";

	d_nbr = ft_atod(str);
	if (d_nbr == 3.14000)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	should_convert_negative_nbr_string_to_double(void)
{
	double	d_nbr = 0.0;
	char	str[5] = "-3.14";

	d_nbr = ft_atod(str);
	if (d_nbr == -3.14)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	should_convert_neg_nbr_starting_with_zero_string_to_double(void)
{
	double	d_nbr = 0.0;
	char	str[5] = "-0.14";

	d_nbr = ft_atod(str);
	if (d_nbr == -0.14)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	should_convert_pos_nbr_starting_with_zero_string_to_double(void)
{
	double	d_nbr = 0.0;
	char	str[5] = "0.14";

	d_nbr = ft_atod(str);
	if (d_nbr == 0.14)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	should_convert_pos_nbr_zero_string_to_double(void)
{
	double	d_nbr = 0.0;
	char	str[4] = "0.0";

	d_nbr = ft_atod(str);
	if (d_nbr == 0.0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	should_convert_neg_nbr_zero_string_to_double(void)
{
	double	d_nbr = 0.0;
	char	str[5] = "-0.0";

	d_nbr = ft_atod(str);
	if (d_nbr == 0.0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_convert_positive_nbr_string_to_double);
	RUN_TEST(should_convert_negative_nbr_string_to_double);
	RUN_TEST(should_convert_neg_nbr_starting_with_zero_string_to_double);
	RUN_TEST(should_convert_pos_nbr_starting_with_zero_string_to_double);
	RUN_TEST(should_convert_pos_nbr_zero_string_to_double);
	RUN_TEST(should_convert_neg_nbr_zero_string_to_double);
	return (0);
}
