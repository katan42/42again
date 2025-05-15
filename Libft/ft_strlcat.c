/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katan <katan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:06:41 by katan             #+#    #+#             */
/*   Updated: 2024/06/24 21:08:08 by katan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dlen;
	unsigned int	slen;

	i = 0;
	j = 0;
	while (dest[j] != '\0')
		j++;
	dlen = j;
	slen = ft_strlen(src);
	if (n == 0 || n <= dlen)
		return (n + slen);
	while (src[i] != '\0' && i < n - dlen -1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dlen + slen);
}
/*
int	main(void)
{
	char	src[] = "#Break The Code";
	char	dest[] = "Champions are those who never quit.";

	printf("src: %s\n dest: %s\n", src, dest);
	printf("size of: %zu\n", ft_strlcat(dest, src, 55));
	printf("src: %s\n dest: %s\n", src, dest);
}*/
