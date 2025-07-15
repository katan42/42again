/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_nbr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 21:17:48 by ka-tan            #+#    #+#             */
/*   Updated: 2025/07/11 12:12:59 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_unsigned_nbr(unsigned int n, int *count)
{
	if (n >= 10)
		ft_print_unsigned_nbr(n / 10, count);
	ft_printchar((n % 10) + '0', count);
}
