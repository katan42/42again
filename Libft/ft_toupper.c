/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katan <katan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:05:47 by katan             #+#    #+#             */
/*   Updated: 2024/06/23 04:03:00 by katan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c - 32;
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

	printf("abcde: %c\n", ft_toupper(str1[0]));
	printf("ABCDE: %c\n", ft_toupper(str2[0]));
	printf("123: %c\n", ft_toupper(str3[0]));
	printf("$#@: %c\n", ft_toupper(str4[0]));
}*/
