/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 21:24:02 by fconde-p          #+#    #+#             */
/*   Updated: 2026/09/16 20:05:47 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static void	free_sphere(t_scene *scene)
{
	t_sphere	*temp;

	temp = NULL;
	while (scene->sphere != NULL)
	{
		temp = scene->sphere;
		scene->sphere = scene->sphere->next;
		free(temp);
	}
}

int	free_scene(t_scene	*scene)
{
	if (scene != NULL)
	{
		free_sphere(scene);
	}
	return (EXIT_SUCCESS);
}
