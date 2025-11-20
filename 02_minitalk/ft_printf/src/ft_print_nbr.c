/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 21:17:36 by ka-tan            #+#    #+#             */
/*   Updated: 2025/07/11 12:13:15 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_nbr(int n, int *count)
{
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		(*count) += 11;
		return ;
	}
	if (n < 0)
	{
		ft_printchar('-', count);
		n = -n;
	}
	if (n >= 10)
		ft_print_nbr(n / 10, count);
	ft_printchar((n % 10) + '0', count);
	return ;
}
