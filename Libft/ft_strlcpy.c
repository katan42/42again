/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katan <katan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:29:57 by katan             #+#    #+#             */
/*   Updated: 2024/06/24 20:51:05 by katan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (src[i] != '\0')
		i++;
	if (size == 0)
		return (i);
	j = 0;
	while (j < size - 1 && src[j] != '\0')
	{
		dest[j] = src[j];
		j++;
	}
	if (size > 0)
		dest[j] = '\0';
	return (i);
}
/*
int	main(void)
{
	char	src[] = "Hello, World!";
	char	dest[20] = "Byebye, World!";
	size_t	copied_length;

	copied_length = ft_strlcpy(dest, src, sizeof(dest));
	printf("source: %s\n dest: %s\n", src, dest);
	printf("length: %zu\n", copied_length);


	char	dest_small[10] = "Hola, Buenas Noches!";
	copied_length = ft_strlcpy(dest_small, src, sizeof(dest_small));
	printf("source: %s\n dest: %s\n", src, dest_small);
	printf("length: %zu\n", copied_length);
}
*/
