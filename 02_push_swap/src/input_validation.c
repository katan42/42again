/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 22:11:39 by ka-tan            #+#    #+#             */
/*   Updated: 2025/12/02 17:49:25 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(char **argv, int capacity)
{
	int		i;
	int		j;
	long	num1;
	long	num2;

	i = 1;
	while (i < capacity)
	{
		num1 = ft_atoi(argv[i]);
		j = i + 1;
		while (j <= capacity)
		{
			num2 = ft_atoi(argv[j]);
			if (num1 == num2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_num(char const *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1])
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	validate_input(char *str)
{
	int		i;
	long	num;
	long	sign;

	if (!check_num(str))
		return (0);
	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	num = 0;
	while (str[i])
	{
		num = num * 10 + (str[i] - '0');
		if (sign == 1 && num > INT_MAX)
			return (0);
		if (sign == -1 && - num < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}
