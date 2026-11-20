#include "./tests.h"
#include "../includes/miniRT.h"

int should_set_valid_sphere_line(void)
{
	char 	*line[] = {"sp", "0,0,20", "20", "255,0,0", NULL};
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

int	should_set_three_valid_spheres(void)
{
	char		*line_st[] = {"sp", "0,0,20", "20", "255,0,0", NULL};
	char		*line_nd[] = {"sp", "3,4.2,69", "11", "100,200,250", NULL};
	char		*line_rd[] = {"sp", "-1,-2,3", "5", "10,20,30", NULL};
	t_scene		scene;
	t_sphere	*temp;
	int			result;

	ft_bzero(&scene, sizeof(scene));
	set_sphere(line_st, &scene);
	set_sphere(line_nd, &scene);
	set_sphere(line_rd, &scene);
	result = EXIT_FAILURE;
	if (scene.sphere->next && scene.sphere->next->next
		&& !scene.sphere->next->next->next
		&& ft_double_equals(scene.sphere->next->next->center.z, 3.0)
			== EXIT_SUCCESS)
		result = EXIT_SUCCESS;
	while (scene.sphere)
	{
		temp = scene.sphere;
		scene.sphere = scene.sphere->next;
		free(temp);
	}
	return (result);
}

int	should_preserve_insertion_order(void)
{
	char		*line1[] = {"sp", "0,0,5", "2", "255,0,0", NULL};   // vermelho
	char		*line2[] = {"sp", "0,0,10", "2", "0,255,0", NULL};  // verde
	char		*line3[] = {"sp", "0,0,15", "2", "0,0,255", NULL};  // azul
	t_scene		scene;
	t_sphere	*temp;
	int			result;

	ft_bzero(&scene, sizeof(scene));
	set_sphere(line1, &scene);
	set_sphere(line2, &scene);
	set_sphere(line3, &scene);
	result = EXIT_FAILURE;
	if (scene.sphere->color.red == 255
		&& scene.sphere->next->color.green == 255
		&& scene.sphere->next->next->color.blue == 255)
		result = EXIT_SUCCESS;
	while (scene.sphere)
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
	RUN_TEST(should_set_three_valid_spheres);
	RUN_TEST(should_preserve_insertion_order);
}
