/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:39:14 by ka-tan            #+#    #+#             */
/*   Updated: 2025/06/12 19:24:53 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

// int	main(void)
// {
// 	char a = 'a';
// 	char b = 'B';
// 	char c = '$';
// 	int	i = '1';

// 	printf("a: %d\n", ft_isalnum(a));
// 	printf("B: %d\n", ft_isalnum(b));
// 	printf("1: %d\n", ft_isalnum(i));
// 	printf("$: %d\n", ft_isalnum(c));
// 	printf("non-ascii: %d\n", ft_isalnum(128));
// }