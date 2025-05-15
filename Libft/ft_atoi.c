/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:06:35 by katan             #+#    #+#             */
/*   Updated: 2025/05/15 17:28:46 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	i;
	long	result;
	long	sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}
/*
int	main(void)
{
	char	str1[] = "     123";
	char	str2[] = "-456";
	char	str3[] = "abc123";
	char	str4[] = "+789";
	
	printf("      123: %d\n", ft_atoi(str1));
	printf("-456: %d\n", ft_atoi(str2));
	printf("abc123: %d\n", ft_atoi(str3));
	printf("+789: %d\n", ft_atoi(str4));
	printf("      123: %d\n", atoi(str1));
	printf("-456: %d\n", atoi(str2));
	printf("abc123: %d\n", atoi(str3));
	printf("+789: %d\n", atoi(str4));
}*/
