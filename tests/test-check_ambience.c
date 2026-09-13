#include "./tests.h"
#include "../includes/miniRT.h"

int	should_succeed_for_valid_ambience_line(void)
{
	char	*line[] = {"A", "0.2", "150,150,150", NULL};
	t_scene	scene;

	ft_bzero(&scene, sizeof(t_scene));
	scene.ambience.is_set = 0;

	if (check_ambience(line, &scene) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_fail_for_lowercase_a(void)
{
	char	*line[] = {"a", "0.2", "150,150,150", NULL};
	t_scene	scene;

	ft_bzero(&scene, sizeof(t_scene));
	scene.ambience.is_set = 0;

	if (check_ambience(line, &scene) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_fail_for_ambience_brightness_below_zero(void)
{
	char	*line[] = {"A", "-0.00001", "150,150,150", NULL};
	t_scene	scene;

	ft_bzero(&scene, sizeof(t_scene));
	scene.ambience.is_set = 0;

	if (check_ambience(line, &scene) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_fail_for_ambience_brightness_above_one(void)
{
	char	*line[] = {"A", "1.00001", "150,150,150", NULL};
	t_scene	scene;

	ft_bzero(&scene, sizeof(t_scene));
	scene.ambience.is_set = 0;

	if (check_ambience(line, &scene) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	should_fail_for_element_identificator_beyond_valid(void)
{
	char	*line[] = {"AA", "0.2", "150,150,150", NULL};
	t_scene	scene;

	ft_bzero(&scene, sizeof(t_scene));
	scene.ambience.is_set = 0;

	if (check_ambience(line, &scene) == EXIT_FAILURE)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

int	main(void)
{
	RUN_TEST(should_succeed_for_valid_ambience_line);
	RUN_TEST(should_fail_for_lowercase_a);
	RUN_TEST(should_fail_for_ambience_brightness_below_zero);
	RUN_TEST(should_fail_for_ambience_brightness_above_one);
	RUN_TEST(should_fail_for_element_identificator_beyond_valid);
}
