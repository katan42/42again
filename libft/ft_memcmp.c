/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:42:58 by ka-tan            #+#    #+#             */
/*   Updated: 2025/06/10 21:25:54 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	i = 0;
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (0);
}

// int	main (void)
// {
// 	unsigned char array1[] = { 0x01, 0x02, 0x03, 0x04, 0x05 };
// 	unsigned char array2[] = { 0x01, 0x02, 0x03, 0x04, 0x06 };
// 	size_t numBytes = sizeof(array1);
// 	int result = ft_memcmp(array1, array2, numBytes);

// 	if (result == 0)
// 	{
// 		printf("The arrays are equal.\n");
// 	}
// 	else if (result < 0)
// 	{
// 		printf("array1 is less than array2.\n");
// 	}
// 	else
// 	{
// 		printf("array1 is greater than array2.\n");
// 	}
// 	return (0);
// }