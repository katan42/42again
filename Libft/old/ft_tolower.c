/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katan <katan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:05:47 by katan             #+#    #+#             */
/*   Updated: 2024/05/23 10:35:35 by katan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c = c + 32;
	}
	return (c);
}
/*
int	main(void)
{
	char	str1[] = "abcde";
	char	str2[] = "ABCDE";
	char	str3[] = "123";
	char	str4[] = "$#@";

	printf("abcde: %c\n", ft_tolower(str1[0]));
	printf("ABCDE: %c\n", ft_tolower(str2[4]));
	printf("123: %c\n", ft_tolower(str3[0]));
	printf("$#@: %c\n", ft_tolower(str4[0]));
}*/
