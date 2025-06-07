/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 21:12:58 by ka-tan            #+#    #+#             */
/*   Updated: 2025/06/07 16:31:08 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (j > i && ft_strchr(set, s1[j - 1]))
		j--;
	str = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + i, j - i + 1);
	return (str);
}

// int	main(void)
// {
// 	char	*result;

// 	result = ft_strtrim("  Hello, World!  ", " ");
// 	printf("Trim space: '%s'\n", result);
// 	free(result);

//     result = ft_strtrim("--Hello, World!--", "-");
//     printf("Trim specific char at ends: '%s'\n", result);
// 	free(result);

// 	result = ft_strtrim("!!!@@@Hello, World!!!@@@", "!@");
// 	printf("Trim diff type of char: '%s'\n", result);
// 	free(result);

// 	result = ft_strtrim("  Hello, World!  ", "");
// 	printf("No trimming: '%s'\n", result);
// 	free(result);

// 	result = ft_strtrim("", " ");
// 	printf("Trim from empty: '%s'\n", result);
// 	free(result);

// 	result = ft_strtrim("abcdefgh", "abcdefgh");
// 	printf("Trim everything: '%s'\n", result);
// 	free(result);

// 	result = ft_strtrim("Hello, World!", "xyz");
// 	printf("Char to trim absent: '%s'\n", result);
// 	free(result);

//     result = ft_strtrim("xxxxx", "x");
// 	printf("Trim same char: '%s'\n", result);
// 	free(result);

//     result = ft_strtrim("\t\n Hello, World! \t\n", " \t\n");
//     printf("Trim whitespace: '%s'\n", result);
//     free(result);

//     result = ft_strtrim(NULL, " ");
//     printf("S1 NUll input: '%s'\n", result);
//     free(result);

//     result = ft_strtrim("Hello, World!", NULL);
//     printf("Null input to trim: '%s'\n", result); 
//     free(result);

// 	result = ft_strtrim(NULL, NULL);
// 	printf("Null both: '%s'\n", result);
// 	free(result);

// 	return (0);
// }
