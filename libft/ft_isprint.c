/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:39:26 by ka-tan            #+#    #+#             */
/*   Updated: 2025/06/12 19:14:41 by ka-tan           ###   ########.fr       */
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

// int	main(void)
// {
// 	char	str1[] = "a";
// 	char	str2[] = "B";
// 	char	str3[] = "1";
// 	char	str4[] = "ê";

// 	printf("a: %d\n", ft_isprint(str1[0]));
// 	printf("B: %d\n", ft_isprint(str2[0]));
// 	printf("1: %d\n", ft_isprint(str3[0]));
// 	printf("ê: %d\n", ft_isprint(str4[0]));
// }
