#include "./tests.h"
#include "../includes/miniRT.h"

int	it_closes_the_window(void)
{
	t_mlx_wrap	wrap;

	ft_bzero(&wrap, sizeof(wrap));
	wrap.mlx = mlx_init();
	wrap.mlx_win = mlx_new_window(wrap.mlx, 800, 600, "test");
	if (close_window(&wrap) == EXIT_SUCCESS)
	{
		// close_window only signals the loop to end.
		// Manual cleanup so the test doesn't leak.
		mlx_destroy_window(wrap.mlx, wrap.mlx_win);
		mlx_destroy_display(wrap.mlx);
		free(wrap.mlx);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(it_closes_the_window);
	return (0);
}
