/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:39:25 by ka-tan            #+#    #+#             */
/*   Updated: 2025/05/16 18:19:19 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
/*
int main(void)
{
	char    str1[] = "a";
	char    str2[] = "B";
	char    str3[] = "1";
	char    str4[] = "1d";
	char    str5[] = "$123&*7";
	char    str6[] = "@";
	char    str7[] = ")";
	char    str8[] = "ABCDEFZ";
	char    str9[] = "ABCDEZ0";

	printf("a: %d\n", ft_isdigit(str1[0]));
	printf("B: %d\n", ft_isdigit(str2[0]));
	printf("1: %d\n", ft_isdigit(str3[0]));
	printf("1d: %d\n", ft_isdigit(str4[0]));
	printf("$123&*7: %d\n", ft_isdigit(str5[1]));
	printf("@: %d\n", ft_isdigit(str6[0]));
	printf("): %d\n", ft_isdigit(str7[0]));
	printf("ABCDEFZ: %d\n", ft_isdigit(str8[0]));
	printf("ABCDEZ0: %d\n", ft_isdigit(str9[0]));
}*/
