/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katan <katan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 22:28:31 by katan             #+#    #+#             */
/*   Updated: 2024/06/23 10:47:58 by katan            ###   ########.fr       */
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
/*
int main(void)
{
	char *message = "Hello, world!";
	ft_putendl_fd(message, 1); // Writes "Hello, world!" to stdout
    return (0);
}
*/
