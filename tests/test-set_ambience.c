#include "./tests.h"
#include "../includes/miniRT.h"

int	should_set_valid_ambience_line(void)
{
	char	*line[] = {"A", "0.2", "100,150,200", NULL};
	t_scene	scene;

	set_ambience(line, &scene);

	if (ft_double_equals(scene.ambience.lighting, 0.2) == EXIT_FAILURE
		|| scene.ambience.color.red != 100
		|| scene.ambience.color.green != 150
		|| scene.ambience.color.blue != 200)
	{
		printf("LIGHTNING  %f\n", scene.ambience.lighting);
		printf("RED  %d\n", scene.ambience.color.red);
		printf("GREEN  %d\n", scene.ambience.color.green);
		printf("BLUE  %d\n", scene.ambience.color.blue);
		printf("COMP  %d\n", ft_double_equals(scene.ambience.lighting, 0.2));
		return (EXIT_FAILURE);
	}
	else
		return (EXIT_SUCCESS);
}

int	main(void)
{
	RUN_TEST(should_set_valid_ambience_line);
}
