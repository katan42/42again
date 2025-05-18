/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:26:54 by ka-tan            #+#    #+#             */
/*   Updated: 2025/05/16 13:32:24 by ka-tan           ###   ########.fr       */
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
		i++;
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

// int	main(void)
// {
// 	char	str1[] = "     123";
// 	char	str2[] = "-456";
// 	char	str3[] = "abc123";
// 	char	str4[] = "+789";
//     char	str5[] = "+++--8987";
//     char	str6[] = "4547545+-+-";
	
// 	printf("      123: %d\n", ft_atoi(str1));
//     printf("      123: %d\n", atoi(str1));
// 	printf("-456: %d\n", ft_atoi(str2));
//     printf("-456: %d\n", atoi(str2));
// 	printf("abc123: %d\n", ft_atoi(str3));
//     printf("abc123: %d\n", atoi(str3));
// 	printf("+789: %d\n", ft_atoi(str4));
// 	printf("+789: %d\n", atoi(str4));
//     printf("+++--8987: %d\n", ft_atoi(str5));
//     printf("+++--8987: %d\n", atoi(str5));
// 	printf("4547545+-+-: %d\n", ft_atoi(str6));
//     printf("4547545+-+-: %d\n", atoi(str6));
// }