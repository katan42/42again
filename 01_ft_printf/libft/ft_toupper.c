/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:42:24 by ka-tan            #+#    #+#             */
/*   Updated: 2025/06/12 19:30:42 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c - 32;
	}
	return (c);
}

// int	main(void)
// {
// 	char	str1[] = "abcde";
// 	char	str2[] = "ABCDE";
// 	char	str3[] = "123";
// 	char	str4[] = "$#@";

// 	printf("abcde: %c\n", ft_toupper(str1[0]));
// 	printf("ABCDE: %c\n", ft_toupper(str2[0]));
// 	printf("123: %c\n", ft_toupper(str3[0]));
// 	printf("$#@: %c\n", ft_toupper(str4[0]));
// }