/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:43:11 by ka-tan            #+#    #+#             */
/*   Updated: 2025/06/15 17:01:37 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i] && i < n -1)
		i++;
	if (s1[i] == s2[i])
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// int	main(void)
// {
// 	char	str1[] = "12345678901234567890";
// 	char	str2[] = "abcdefghijabcde";
// 	char	str3[] = " ";

// 	printf("str1-str2,20: %d\n", ft_strncmp(str1, str2, 20));
// 	printf("str1-str2,15: %d\n", ft_strncmp(str1, str2, 15));
// 	printf("str1-str2,10: %d\n", ft_strncmp(str1, str2, 10));
// 	printf("str2-str1,20: %d\n", ft_strncmp(str2, str1, 20));
// 	printf("str2-str1,15: %d\n", ft_strncmp(str2, str1, 15));
// 	printf("str2-str1,10: %d\n", ft_strncmp(str2, str1, 10));
// 	printf("str3-str1,15: %d\n", ft_strncmp(str3, str1, 15));
// 	printf("str1-str3,15: %d\n", ft_strncmp(str1, str3, 15));
// }