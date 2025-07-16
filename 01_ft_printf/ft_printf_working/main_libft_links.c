/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 22:13:09 by ka-tan            #+#    #+#             */
/*   Updated: 2025/07/10 18:09:59 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <limits.h>
#include <stdio.h>
#include "libft/libft.h"

int main(void)
{
	char *s = "Hello Libft!";
	printf("Length of \"%s\" = %zu\n", s, ft_strlen(s));

	if (ft_isalpha('A'))
		printf("'A' is alpha!\n");

	printf("ft_Atoi(\"   -42\") = %d\n", ft_atoi("   -42"));

	return (0);
}

