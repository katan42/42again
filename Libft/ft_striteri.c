/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 21:14:58 by ka-tan            #+#    #+#             */
/*   Updated: 2025/05/16 21:15:14 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}
/*
#include <ctype.h>

void	convert_case(unsigned int index, char *c)
{
	if (index == 0)
	{
		*c = ft_toupper(*c);
	}
	else
	{
		*c = ft_tolower(*c);
	}
}

int	main(void)
{
	char	text[] = "hello WoRlD how aRe You";

	printf("Original: %s\n", text);
	ft_striteri(text, &convert_case);
	printf("Converted: %s\n", text);
	return (0);
}
*/
