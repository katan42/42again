/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:42:51 by ka-tan            #+#    #+#             */
/*   Updated: 2025/06/12 19:13:59 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
		{
			return (&str[i]);
		}
		i++;
	}
	return (NULL);
}

// //The  memchr()  function  scans  the initial n bytes of the memory area
//pointed to by s for the first instance of c.  Both c and the bytes 
//of the memory area pointed to by s are interpreted as unsigned char.
// int main(void)
// {
// 	const char *str = "Hiello, worldeeeeeei!";
// 	char *ptr = ft_memchr(str, 'i', 15);

// 	if(ptr)
// 		printf("ft_memchr\nFound character 'i' at position: %ld\n", ptr-str+1);
// 	else
// 		printf("Character not found within 'n' bytes\n");
// 	return (0);
// }