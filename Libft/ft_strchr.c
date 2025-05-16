/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:41:50 by ka-tan            #+#    #+#             */
/*   Updated: 2025/05/16 20:34:07 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int i)
{
	unsigned char	c;

	c = (unsigned char)i;
	while (*s || c == '\0')
	{
		if (*s++ == c)
		{
			return ((char *)--s);
		}
	}
	return (NULL);
}
/*
int main(void)
{
	const char *str = "Hello, world!";
	char *ptr = ft_strchr(str, 'o');
	  
	printf("ft_strchr\nFound character 'o' at position: %ld\n", ptr-str+1);
	return 0;
}
*/
