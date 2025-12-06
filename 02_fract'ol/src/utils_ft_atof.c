/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft_atof.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 00:50:42 by ka-tan            #+#    #+#             */
/*   Updated: 2025/12/03 14:30:29 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

const char	*handle_prefix(const char *str, int *sign)
{
	*sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign = -1;
		str++;
	}
	return (str);
}

double	process_whole_number(const char **str)
{
	double	result;

	result = 0.0;
	while (**str >= '0' && **str <= '9')
	{
		result = result * 10 + (**str - '0');
		(*str)++;
	}
	return (result);
}

double	process_fraction(const char *str)
{
	double	result;
	double	fraction;

	result = 0.0;
	fraction = 0.1;
	while (*str >= '0' && *str <= '9')
	{
		result = result + (*str - '0') * fraction;
		fraction *= 0.1;
		str++;
	}
	return (result);
}

double	ft_atof(const char *str)
{
	double		result;
	int			sign;
	const char	*ptr;

	ptr = handle_prefix(str, &sign);
	result = process_whole_number(&ptr);
	if (*ptr == '.')
		result += process_fraction(ptr + 1);
	return (result * sign);
}
