/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:41:41 by ka-tan            #+#    #+#             */
/*   Updated: 2025/06/12 19:12:15 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d == s || n == 0)
		return (dest);
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		while (n)
		{
			*(d + n - 1) = *(s + n - 1);
			n--;
		}
	}
	return (dest);
}

// int	main(void)
// {
// 	char	str1[] = "Hello, World!";
// 	char	str2[] = "12345678901234567890";

// 	printf("Before memmove, str1: %s\n", str1);
// 	ft_memmove(str2, str1, 13);
// 	printf("After memmove to str2: %s\n", str2);
// 	ft_memmove(str1 + 7, str1, 6);
// 	printf("After overlapping memmove, str1: %s\n", str1);
// 	return (0);
// }
