/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:42:06 by ka-tan            #+#    #+#             */
/*   Updated: 2025/06/12 17:56:32 by ka-tan           ###   ########.fr       */
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
	while (j < n && dest[j] != '\0')
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
// 	char	dest[100] = "Champions are those who never quit.";

// 	printf("bef src: %s\n bef dest: %s\n", src, dest);
// 	printf("size of: %zu\n", ft_strlcat(dest, src, 55));
// 	printf("aft src: %s\n aft dest: %s\n", src, dest);
// }
// not required in manual to guard against non-nullterminated
// but matches behaviour of real strlcat() on systems like BSD
// #include <string.h>
// #include <bsd/string.h>

// int	main(void)
// {
// 	char *dest = malloc(15);
// 	if (!dest)
// 		return (1);

// 	memset(dest, 'r', 15);
// 	size_t result = ft_strlcat(dest, "lorem ipsum dolor sit amet", 0);

// 	printf("Return value: %zu\n", result);
// 	write(1, "Final dest: ", 12);
// 	write(1, dest, 15);
// 	write(1, "\n", 1);

// 	free(dest);
// 	return (0);
// }