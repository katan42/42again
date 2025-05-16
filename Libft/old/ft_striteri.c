/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri 2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katan <katan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 22:24:42 by katan             #+#    #+#             */
/*   Updated: 2024/06/23 23:34:36 by katan            ###   ########.fr       */
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