/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 21:24:02 by fconde-p          #+#    #+#             */
/*   Updated: 2026/09/13 21:30:30 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	free_scene(t_scene	*scene)
{
	if (scene->sphere != NULL)
		free(scene->sphere);
	return (EXIT_SUCCESS);
}
