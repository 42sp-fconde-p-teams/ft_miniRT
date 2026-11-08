#include "./tests.h"
#include "../includes/miniRT.h"

// limit_rgb should return the value itself when in range [0, 255].
int	should_limit_rgb_keep_value_in_range(void)
{
	if (limit_rgb(0) == 0
		&& limit_rgb(100) == 100
		&& limit_rgb(255) == 255)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// limit_rgb should clamp negative values to 0.
int	should_limit_rgb_clamp_to_zero(void)
{
	if (limit_rgb(-1) == 0
		&& limit_rgb(-100) == 0
		&& limit_rgb(-99999) == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// limit_rgb should clamp values above 255 to 255.
int	should_limit_rgb_clamp_to_255(void)
{
	if (limit_rgb(256) == 255
		&& limit_rgb(300) == 255
		&& limit_rgb(99999) == 255)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// add_lights should sum colors when the result stays below 255.
int	should_add_lights_sum_in_range(void)
{
	t_rgb	a = (t_rgb){10, 20, 30};
	t_rgb	d = (t_rgb){40, 50, 60};
	t_rgb	s = (t_rgb){1, 2, 3};
	t_rgb	res = add_lights(a, d, s);

	if (res.red == 51 && res.green == 72 && res.blue == 93)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// add_lights should clamp each channel independently when it exceeds 255.
int	should_add_lights_clamp_each_channel(void)
{
	t_rgb	a = (t_rgb){200, 10, 250};
	t_rgb	d = (t_rgb){100, 20, 100};
	t_rgb	s = (t_rgb){50, 30, 50};
	t_rgb	res = add_lights(a, d, s);

	// red: 350 -> 255, green: 60 -> 60, blue: 400 -> 255
	if (res.red == 255 && res.green == 60 && res.blue == 255)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// add_lights with all zeros should return black (0, 0, 0).
int	should_add_lights_return_black(void)
{
	t_rgb	zero = (t_rgb){0, 0, 0};
	t_rgb	res = add_lights(zero, zero, zero);

	if (res.red == 0 && res.green == 0 && res.blue == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// add_lights with only one non-zero input should return that input.
int	should_add_lights_with_only_one_nonzero(void)
{
	t_rgb	zero = (t_rgb){0, 0, 0};
	t_rgb	val = (t_rgb){100, 150, 200};
	t_rgb	res = add_lights(val, zero, zero);

	if (res.red == 100 && res.green == 150 && res.blue == 200)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_limit_rgb_keep_value_in_range);
	RUN_TEST(should_limit_rgb_clamp_to_zero);
	RUN_TEST(should_limit_rgb_clamp_to_255);
	RUN_TEST(should_add_lights_sum_in_range);
	RUN_TEST(should_add_lights_clamp_each_channel);
	RUN_TEST(should_add_lights_return_black);
	RUN_TEST(should_add_lights_with_only_one_nonzero);
}
