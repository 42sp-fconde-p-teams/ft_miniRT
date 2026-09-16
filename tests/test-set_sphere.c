#include "./tests.h"
#include "../includes/miniRT.h"

int should_set_valid_sphere_line(void)
{
	char 	*line[] = {"sp", "0,0,20", "20", "255,0,0", NULL};
	t_scene	scene;

	ft_bzero(&scene, sizeof(scene));
	set_sphere(line, &scene);
	if (ft_double_equals(scene.sphere->center.x, 0.0) == EXIT_FAILURE || ft_double_equals(scene.sphere->center.y, 0.0) == EXIT_FAILURE || ft_double_equals(scene.sphere->center.z, 20.0) == EXIT_FAILURE || ft_double_equals(scene.sphere->diameter, 20.0) == EXIT_FAILURE || scene.sphere->color.red != 255 || scene.sphere->color.green != 0 || scene.sphere->color.blue != 0 || scene.sphere->next != NULL)
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

int should_set_two_valid_spheres(void)
{
	char		*line_st[] = {"sp", "0,0,20", "20", "255,0,0", NULL};
	char		*line_nd[] = {"sp", "3,4.2,69", "11", "100,200,250", NULL};
	t_scene		scene;
	t_sphere	*temp;
	int			result = 0;

	ft_bzero(&scene, sizeof(scene));
	set_sphere(line_st, &scene);
	set_sphere(line_nd, &scene);
	if (ft_double_equals(scene.sphere->center.x, 0.0) == EXIT_FAILURE
		|| ft_double_equals(scene.sphere->center.y, 0.0) == EXIT_FAILURE
		|| ft_double_equals(scene.sphere->center.z, 20.0) == EXIT_FAILURE
		|| ft_double_equals(scene.sphere->diameter, 20.0) == EXIT_FAILURE
		|| scene.sphere->color.red != 255
		|| scene.sphere->color.green != 0
		|| scene.sphere->color.blue != 0
		|| scene.sphere->next == NULL
		|| ft_double_equals(scene.sphere->next->center.x, 3.0) == EXIT_FAILURE
		|| ft_double_equals(scene.sphere->next->center.y, 4.2) == EXIT_FAILURE
		|| ft_double_equals(scene.sphere->next->center.z, 69.0) == EXIT_FAILURE
		|| ft_double_equals(scene.sphere->next->diameter, 11.0) == EXIT_FAILURE
		|| scene.sphere->next->color.red != 100
		|| scene.sphere->next->color.green != 200
		|| scene.sphere->next->color.blue != 250
		|| scene.sphere->next->next != NULL)
		result = EXIT_FAILURE;
	else
		result = EXIT_SUCCESS;
	while (scene.sphere != NULL)
	{
		temp = scene.sphere;
		scene.sphere = scene.sphere->next;
		free(temp);
	}
	return (result);
}

int main(void)
{
	RUN_TEST(should_set_valid_sphere_line);
	RUN_TEST(should_set_two_valid_spheres);
}
