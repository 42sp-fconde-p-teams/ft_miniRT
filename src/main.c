/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 20:37:58 by fconde-p          #+#    #+#             */
/*   Updated: 2026/07/25 20:57:36 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	main(int ac, char **av)
{
	ft_printf("Success: %d\n", sample_return(EXIT_SUCCESS));
	ft_printf("Fail: %d\n", sample_return(EXIT_FAILURE));
	return (0);
}