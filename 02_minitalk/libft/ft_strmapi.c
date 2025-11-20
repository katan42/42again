/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 21:14:47 by ka-tan            #+#    #+#             */
/*   Updated: 2025/06/12 18:28:19 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// #include <ctype.h>

// char	convert_case(unsigned int index, char c)
// {
// 	if (index == 0)
// 	{
// 		return (ft_toupper(c));
// 	}
// 	else
// 	{
// 		return (ft_tolower(c));
// 	}
// }

// int	main(void)
// {
// 	char	text[] = "hello WoRlD how aRe You";
// 	char	*converted_text = ft_strmapi(text, &convert_case);

// 	if (converted_text)
// 	{
// 		printf("Original: %s\n", text);
// 		printf("Converted: %s\n", converted_text);
// 		free(converted_text);
// 	}
// 	else
// 	{
// 		printf("Memory allocation failed!\n");
// 	}
// 	return (0);
// }