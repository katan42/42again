/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 21:17:41 by ka-tan            #+#    #+#             */
/*   Updated: 2025/07/11 12:12:52 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hexptr(unsigned long n, int *count)
{
	char	*base_character;

	base_character = "0123456789abcdef";
	if (n >= 16)
		ft_print_hexptr(n / 16, count);
	ft_printchar(base_character[n % 16], count);
	return ;
}

void	ft_print_ptr(void *ptr, int *count)
{
	if (ptr == 0)
	{
		ft_printstr("(nil)", count);
		return ;
	}
	write(1, "0x", 2);
	(*count) += 2;
	ft_print_hexptr((unsigned long)ptr, count);
}
