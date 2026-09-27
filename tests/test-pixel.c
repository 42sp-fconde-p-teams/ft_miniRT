#include "./tests.h"
#include "../includes/miniRT.h"

// Red should land in byte 2 of the pixel.
int	should_write_red_to_byte_2(void)
{
	t_img	img;
	char	buffer[4] = {0};
	t_rgb	color;

	img.addr = buffer;
	img.bits_per_pixel = 32;
	img.line_length = 4;
	color = (t_rgb){255, 0, 0};
	ft_put_pixel(&img, 0, 0, color);
	if ((unsigned char)buffer[0] == 0
		&& (unsigned char)buffer[1] == 0
		&& (unsigned char)buffer[2] == 255
		&& (unsigned char)buffer[3] == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Green should land in byte 1.
int	should_write_green_to_byte_1(void)
{
	t_img	img;
	char	buffer[4] = {0};
	t_rgb	color;

	img.addr = buffer;
	img.bits_per_pixel = 32;
	img.line_length = 4;
	color = (t_rgb){0, 255, 0};
	ft_put_pixel(&img, 0, 0, color);
	if ((unsigned char)buffer[0] == 0
		&& (unsigned char)buffer[1] == 255
		&& (unsigned char)buffer[2] == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Blue should land in byte 0.
int	should_write_blue_to_byte_0(void)
{
	t_img	img;
	char	buffer[4] = {0};
	t_rgb	color;

	img.addr = buffer;
	img.bits_per_pixel = 32;
	img.line_length = 4;
	color = (t_rgb){0, 0, 255};
	ft_put_pixel(&img, 0, 0, color);
	if ((unsigned char)buffer[0] == 255
		&& (unsigned char)buffer[1] == 0
		&& (unsigned char)buffer[2] == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// White should set all 3 color bytes.
int	should_write_white(void)
{
	t_img	img;
	char	buffer[4] = {0};
	t_rgb	color;

	img.addr = buffer;
	img.bits_per_pixel = 32;
	img.line_length = 4;
	color = (t_rgb){255, 255, 255};
	ft_put_pixel(&img, 0, 0, color);
	if ((unsigned char)buffer[0] == 255
		&& (unsigned char)buffer[1] == 255
		&& (unsigned char)buffer[2] == 255)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Pixel at (1, 1) with line_length 16 must land at offset 20.
int	should_write_pixel_at_offset(void)
{
	t_img	img;
	char	buffer[32] = {0};
	t_rgb	color;

	img.addr = buffer;
	img.bits_per_pixel = 32;
	img.line_length = 16;   // 4 pixels por linha
	color = (t_rgb){10, 20, 30};
	ft_put_pixel(&img, 1, 1, color);
	// offset = y * line_length + x * 4 = 1 * 16 + 1 * 4 = 20
	if ((unsigned char)buffer[20] == 30
		&& (unsigned char)buffer[21] == 20
		&& (unsigned char)buffer[22] == 10)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Writing to (0, 0) should leave the rest of the buffer untouched.
int	should_not_touch_other_pixels(void)
{
	t_img	img;
	char	buffer[8] = {0};
	t_rgb	color;

	img.addr = buffer;
	img.bits_per_pixel = 32;
	img.line_length = 8;
	color = (t_rgb){255, 0, 0};
	ft_put_pixel(&img, 0, 0, color);
	if ((unsigned char)buffer[4] == 0
		&& (unsigned char)buffer[5] == 0
		&& (unsigned char)buffer[6] == 0
		&& (unsigned char)buffer[7] == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_write_red_to_byte_2);
	RUN_TEST(should_write_green_to_byte_1);
	RUN_TEST(should_write_blue_to_byte_0);
	RUN_TEST(should_write_white);
	RUN_TEST(should_write_pixel_at_offset);
	RUN_TEST(should_not_touch_other_pixels);
}
