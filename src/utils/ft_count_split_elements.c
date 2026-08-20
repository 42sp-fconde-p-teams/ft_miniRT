/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_split_elements.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 20:15:11 by fconde-p          #+#    #+#             */
/*   Updated: 2026/08/20 19:51:04 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

size_t	count_split_elements(char **splited)
{
	size_t	i;

	i = 0;
	if (!splited)
		return (0);
	while (splited[i])
		i++;
	return (i);
}
