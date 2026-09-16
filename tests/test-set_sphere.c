#include "./tests.h"
#include "../includes/miniRT.h"

int	should_set_valid_sphere_line(void)
{
	char	*line[] = {"sp", "0,0,20", "20", "255,0,0", NULL};
	t_scene	scene;

	ft_bzero(&scene, sizeof(scene));
	set_sphere(line, &scene);
	if (ft_double_equals(scene.sphere->center.x, 0.0) == EXIT_FAILURE
		|| ft_double_equals(scene.sphere->center.y, 0.0) == EXIT_FAILURE
		|| ft_double_equals(scene.sphere->center.z, 20.0) == EXIT_FAILURE
		|| ft_double_equals(scene.sphere->diameter, 20.0) == EXIT_FAILURE
		|| scene.sphere->color.red != 255
		|| scene.sphere->color.green != 0
		|| scene.sphere->color.blue != 0
		|| scene.sphere->next != NULL)
	{
		if (scene.sphere)
		{
			free(scene.sphere);
		}
		return (EXIT_FAILURE);
	}
	else
	{
		if (scene.sphere)
		{
			free(scene.sphere);
		}
			return (EXIT_SUCCESS);
	}
}

int	main(void)
{
	RUN_TEST(should_set_valid_sphere_line);
}
