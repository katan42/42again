/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:43:21 by ka-tan            #+#    #+#             */
/*   Updated: 2025/05/16 20:36:42 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*ptr;
	unsigned char	a;

	a = (unsigned char)c;
	ptr = NULL;
	while (*s || a == '\0')
	{
		if (*s == (unsigned char)a)
		{
			ptr = (char *)s;
			if (!*s)
				break ;
		}
		s++;
	}
	return (ptr);
}
/*int main(void)
{
	const char *str = "Hello, world!";
	char *ptr = ft_strrchr(str, 'o');
	    
	printf("ft_strrchr\nFound last character 'o' at position: %ld\n", ptr-str+1);
	return 0;
}
*/
