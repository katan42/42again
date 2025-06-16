/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:42:20 by ka-tan            #+#    #+#             */
/*   Updated: 2025/06/12 19:09:20 by ka-tan           ###   ########.fr       */
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

// int	main(void)
// {
// 	char	str1[] = "abcde";
// 	char	str2[] = "ABCDE";
// 	char	str3[] = "123";
// 	char	str4[] = "$#@";

// 	printf("abcde: %c\n", ft_tolower(str1[0]));
// 	printf("ABCDE: %c\n", ft_tolower(str2[4]));
// 	printf("123: %c\n", ft_tolower(str3[0]));
// 	printf("$#@: %c\n", ft_tolower(str4[0]));
// }
