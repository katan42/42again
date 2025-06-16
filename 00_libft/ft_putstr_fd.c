/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 21:15:55 by ka-tan            #+#    #+#             */
/*   Updated: 2025/06/12 17:39:17 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
	{
		return ;
	}
	write (fd, s, ft_strlen(s));
}

// int main(void)
// {
// 	char *message = "Hello, world!";
// 	ft_putstr_fd(message, 1);
// 	return (0);
// }
