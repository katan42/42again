/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katan <katan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:35:13 by katan             #+#    #+#             */
/*   Updated: 2024/06/24 21:31:52 by katan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	if (!dest && !src)
		return (dest);
	d = (char *)dest;
	s = (char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
#include <string.h>

int main(void)
{
	char src[] = "Hello, World!";
	char dest[50] = "12345678901234567890"; 
	char dest_standard[50] = "09876543210987654321";
	
    printf("Destination: %s\n", dest);
    printf("Destination (standard): %s\n", dest_standard);
	
	ft_memcpy(dest, src, strlen(src) + 1); 
	printf("Source: %s\n", src);
    printf("Destination (ft_memcpy): %s\n", dest);
    memcpy(dest_standard, src, strlen(src) + 1);
    printf("Destination (standard memcpy): %s\n", dest_standard);
    return (0);
}
*/
