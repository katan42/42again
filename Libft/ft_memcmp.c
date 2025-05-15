/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katan <katan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:37:19 by katan             #+#    #+#             */
/*   Updated: 2024/06/23 06:35:02 by katan            ###   ########.fr       */
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
/*
int	main (void)
{
	unsigned char array1[] = { 0x01, 0x02, 0x03, 0x04, 0x05 };
	unsigned char array2[] = { 0x01, 0x02, 0x03, 0x04, 0x06 };
	size_t numBytes = sizeof(array1);
	int result = ft_memcmp(array1, array2, numBytes);

	if (result == 0)
	{
		printf("The arrays are equal.\n");
	}
	else if (result < 0)
	{
		printf("array1 is less than array2.\n");
	}
	else
	{
		printf("array1 is greater than array2.\n");
	}
	return (0);
}
*/
