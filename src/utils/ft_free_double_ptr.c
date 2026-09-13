/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_double_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 11:24:46 by fconde-p          #+#    #+#             */
/*   Updated: 2026/09/12 21:35:01 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	ft_free_double_ptr(char **s, size_t j)
{
	int	count;

	count = (int)j - 1;
	while (*s[count])
	{
		while (count >= 0)
		{
			free(s[count]);
			count--;
		}
		free(s);
		return (0);
	}
	return (1);
}
