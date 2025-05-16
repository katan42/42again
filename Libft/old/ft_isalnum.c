/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:52:29 by katan             #+#    #+#             */
/*   Updated: 2025/05/15 17:28:57 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
/*
int	main(void)
{
	char a = 'a';
	char b = 'B';
	char c = '$';
	
	printf("a: %d\n", ft_isalnum(a));
	printf("B: %d\n", ft_isalnum(b));
	printf("1: %d\n", ft_isalnum(1));
	printf("$: %d\n", ft_isalnum(c));
}*/
