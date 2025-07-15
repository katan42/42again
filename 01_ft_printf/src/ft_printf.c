/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 21:17:53 by ka-tan            #+#    #+#             */
/*   Updated: 2025/07/11 12:12:00 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_check(char specifier, va_list *args, int *count)
{
	if (specifier == 'c')
		ft_printchar(va_arg(*args, int), count);
	else if (specifier == 's')
		ft_printstr(va_arg(*args, char *), count);
	else if (specifier == 'p')
		ft_print_ptr(va_arg(*args, void *), count);
	else if (specifier == 'd' || specifier == 'i')
		ft_print_nbr(va_arg(*args, int), count);
	else if (specifier == 'u')
		ft_print_unsigned_nbr(va_arg(*args, unsigned int), count);
	else if (specifier == 'x' || specifier == 'X')
		ft_print_hex(va_arg(*args, unsigned int), count, specifier);
	else if (specifier == '%')
		ft_printchar('%', count);
	else
		ft_printchar(specifier, count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			i++;
			ft_printf_check(s[i], &args, &count);
		}
		else
			ft_printchar(s[i], &count);
		i++;
	}
	va_end(args);
	return (count);
}
