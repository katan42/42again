/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 21:17:10 by ka-tan            #+#    #+#             */
/*   Updated: 2025/07/11 12:13:07 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex(unsigned int n, int *count, char conversion)
{
	char	*base_character;

	if (conversion == 'x')
		base_character = "0123456789abcdef";
	else
		base_character = "0123456789ABCDEF";
	if (n >= 16)
		ft_print_hex(n / 16, count, conversion);
	ft_printchar(base_character[n % 16], count);
	return ;
}
