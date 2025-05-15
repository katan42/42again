/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katan <katan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:19:54 by katan             #+#    #+#             */
/*   Updated: 2024/06/24 22:40:18 by katan            ###   ########.fr       */
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
