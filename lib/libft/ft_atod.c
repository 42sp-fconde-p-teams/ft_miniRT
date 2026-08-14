/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 20:15:11 by fconde-p          #+#    #+#             */
/*   Updated: 2026/08/14 20:34:58 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	gen_int_part(char *ptr, double acc)
{
	while (ft_isdigit(*ptr) > 0)
	{
		acc = acc * 10.0 + (*ptr - '0');
		ptr++;
	}
	return (acc);
}

static double	gen_fractional_part(char *ptr, double acc)
{
	double	divisor;

	divisor = 10.0;
	while (ft_isdigit(*ptr) > 0)
	{
		acc += (*ptr - '0') / divisor;
		divisor *= 10.0;
		ptr++;
	}
	return (acc);
}

static double	check_sign(char *ptr, double *sign)
{
	if (*ptr == '-' || *ptr == '+')
	{
		if (ft_isdigit(*(ptr + 1)) == 0)
			return (0);
		if (*ptr == '-')
			*sign = -1.0;
		ptr++;
	}
	return (1);
}

double	ft_atod(const char *nptr)
{
	double	sign;
	double	acc;
	double	*ptr_sign;

	ptr_sign = &sign;
	sign = 1.0;
	acc = 0.0;
	while (*nptr >= 0 && *nptr <= 32)
		nptr++;
	if (ft_isalpha(*nptr))
		return (0);
	if (!check_sign((char *)nptr, ptr_sign))
		return (0);
	while (*nptr)
	{
		if (ft_isdigit(*nptr) > 0)
		{
			acc = gen_long((char *)nptr, acc);
			return (acc * sign);
		}
		nptr++;
	}
	return (acc * sign);
}
