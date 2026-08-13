/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 20:37:58 by fconde-p          #+#    #+#             */
/*   Updated: 2026/08/12 13:05:25 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Error\nExpected exactly one parameter!\n");
		return (1);
	}
	read_file(av[1]);
	init_window();
	return (0);
}
