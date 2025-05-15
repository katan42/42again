/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katan <katan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:15:07 by katan             #+#    #+#             */
/*   Updated: 2024/06/24 22:36:36 by katan            ###   ########.fr       */
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
