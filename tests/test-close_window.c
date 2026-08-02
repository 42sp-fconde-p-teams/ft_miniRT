#include "./tests.h"
#include "../includes/miniRT.h"

int	it_closes_the_window(void)
{

	t_mlx_wrap	mlx_wrap;

	mlx_wrap.mlx = mlx_init();
	mlx_wrap.mlx_win = mlx_new_window(mlx_wrap.mlx, 800, 600, "FT_miniRT");
	close_window(&mlx_wrap);
	if (mlx_wrap.mlx_win == NULL && mlx_wrap.mlx == NULL)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(it_closes_the_window);
	return (0);
}
