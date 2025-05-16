/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katan <katan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 08:49:52 by katan             #+#    #+#             */
/*   Updated: 2024/05/23 10:29:34 by katan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	return (0);
}
/*
int	main(void)
{
	char	str1[] = "a";
	char	str2[] = "B";
	char	str3[] = "1";
	char	str4[] = "ê";

	printf("a: %d\n", ft_isprint(str1[0]));
	printf("B: %d\n", ft_isprint(str2[0]));
	printf("1: %d\n", ft_isprint(str3[0]));
	printf("ê: %d\n", ft_isprint(str4[0]));
}*/
