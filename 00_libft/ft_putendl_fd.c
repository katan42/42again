/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 21:16:18 by ka-tan            #+#    #+#             */
/*   Updated: 2025/06/12 17:26:45 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL)
	{
		return ;
	}
	write (fd, s, ft_strlen(s));
	write (fd, "\n", 1);
}
// printf writes to terminal(1)
//fn increases flexibility to change fd 
// int main(void)
// {
// 	char *message = "Hello, world!";
// 	ft_putendl_fd(message, 1);
//     return (0);
// }
