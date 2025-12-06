/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 20:39:07 by ka-tan            #+#    #+#             */
/*   Updated: 2025/11/18 17:52:22 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
//# include "libft.h"

void	ft_printchar(char c, int *count);
void	ft_printstr(const char *s, int *count);
void	ft_print_ptr(void *ptr, int *count);
void	ft_print_nbr(int n, int *count);
void	ft_print_unsigned_nbr(unsigned int n, int *count);
void	ft_print_hex(unsigned int n, int *count, char conversion);
int		ft_printf(const char *s, ...);
#endif
