/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:42:06 by ka-tan            #+#    #+#             */
/*   Updated: 2025/06/07 16:15:57 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	if (!dest || !src)
		return (0);
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

// int	main(void)
// {
// 	char	src[] = "#Break The Code";
// 	char	dest[] = "Champions are those who never quit.";

// 	printf("src: %s\n dest: %s\n", src, dest);
// 	printf("size of: %zu\n", ft_strlcat(dest, src, 55));
// 	printf("src: %s\n dest: %s\n", src, dest);
// }
