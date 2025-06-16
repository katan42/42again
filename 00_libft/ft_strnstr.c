/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:43:16 by ka-tan            #+#    #+#             */
/*   Updated: 2025/06/12 19:01:08 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*little)
	{
		return ((char *)big);
	}
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len
			&& big[i + j] != '\0' && little[j] != '\0')
			j++;
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

// int main(void)
// {
// 	const char *big = "Hello, world!";
// 	const char *little = "lo";
// 	char *ptr = ft_strnstr(big, little, 10);

// 	if (ptr)
// 		printf("ft_strnstr\nFound little at position: %s\n", ptr);
// 	else
// 		printf("not found\n");
// 	return (0);
// }