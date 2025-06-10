/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:38:50 by ka-tan            #+#    #+#             */
/*   Updated: 2025/06/10 19:41:02 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// int main(void)
// {   
// 	char    str[] = "Let's go HOME";
	
// 	printf("before bzero %s\n", str);
// 	ft_bzero(str, 5);
// 	printf("after bzero %s\n", str);
// }