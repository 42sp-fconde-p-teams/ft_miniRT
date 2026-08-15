/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 20:15:11 by fconde-p          #+#    #+#             */
/*   Updated: 2026/08/15 18:43:58 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static double	gen_int_part(char **ptr, double acc)
{
	while (**ptr && ft_isdigit(**ptr) > 0)
	{
		acc = acc * 10.0 + (**ptr - '0');
		(*ptr)++;
	}
	return (acc);
}

static double	gen_fractional_part(char **ptr, double acc)
{
	double	divisor;

	divisor = 10.0;
	while (**ptr && ft_isdigit(**ptr) > 0)
	{
		acc += (**ptr - '0') / divisor;
		divisor *= 10.0;
		(*ptr)++;
	}
	return (acc);
}

static int	check_sign(char **ptr, double *sign)
{
	if (**ptr == '-' || **ptr == '+')
	{
		if (**ptr == '-')
			*sign = -1.0;
		(*ptr)++;
	}
	return (1);
}

double	ft_atod(char *nptr)
{
	double	sign;
	double	acc;

	sign = 1.0;
	acc = 0.0;
	if (!check_sign(&nptr, &sign))
		return (0);
	if (ft_isdigit(*nptr) > 0)
	{
		acc = gen_int_part(&nptr, acc);
	}
	if (*nptr == '.')
	{
		nptr++;
		acc = gen_fractional_part(&nptr, acc);
	}
	return (acc * sign);
}
