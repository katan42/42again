/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:41:50 by ka-tan            #+#    #+#             */
/*   Updated: 2025/06/15 16:58:03 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int i)
{
	char	c;

	c = (char)i;
	while (*s || c == '\0')
	{
		if (*s++ == c)
			return ((char *)--s);
	}
	return (NULL);
}
// this s++ , --s is a trick to reduce lines, but totally unnecessary
// if (*s == c)
//return ((char *)s);
//s++;
// int main(void)
// {
// 	const char *str = "Hello, world!";
// 	char *ptr = ft_strchr(str, 'o');

// 	printf("ft_strchr\nFound character 'o' at position: %ld\n", ptr-str+1);
// 	return 0;
// }
