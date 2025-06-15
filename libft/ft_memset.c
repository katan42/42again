/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:39:28 by ka-tan            #+#    #+#             */
/*   Updated: 2025/06/12 16:57:04 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = (unsigned char)c;
		ptr++;
		n--;
	}
	return (s);
}

// int main(void)
// {
// 	char	str[] = "Let's go HOME";

// 	printf("str before memset %s\n", str);
// 	ft_memset(str,'d', 5);
// 	printf("str after memset %s\n", str);
// 	printf("memset returns: %s\n", (char *)ft_memset(str,'d', 5));
// }
