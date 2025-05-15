/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katan <katan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 22:17:37 by katan             #+#    #+#             */
/*   Updated: 2024/06/24 23:10:57 by katan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = ft_strlen(s1);
	if (!s1 || !set)
	{
		return (NULL);
	}
	while (s1[i] && ft_strchr(set, s1[i]))
	{
		i++;
	}
	while (j > i && ft_strchr(set, s1[j - 1]))
	{
		j--;
	}
	str = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + i, j - i + 1);
	str[j - i + 1] = '\0';
	return (str);
}
/*
int	main(void)
{
	char	*result;

	result = ft_strtrim("  Hello, World!  ", " ");
	printf("Trim space: '%s'\n", result);
	free(result);

    result = ft_strtrim("--Hello, World!--", "-");
    printf("Trim specific char at ends: '%s'\n", result);
	free(result);

	result = ft_strtrim("!!!@@@Hello, World!!!@@@", "!@");
	printf("Trim diff type of char: '%s'\n", result);
	free(result);

	result = ft_strtrim("  Hello, World!  ", "");
	printf("No trimming: '%s'\n", result);
	free(result);

	result = ft_strtrim("", " ");
	printf("Trim from empty: '%s'\n", result);
	free(result);

	result = ft_strtrim("abcdefgh", "abcdefgh");
	printf("Trim everything: '%s'\n", result);
	free(result);
	
	result = ft_strtrim("Hello, World!", "xyz");
	printf("Char to trim absent: '%s'\n", result);
	free(result);

    result = ft_strtrim("xxxxx", "x");
	printf("Trim same char: '%s'\n", result);
	free(result);

    result = ft_strtrim("\t\n Hello, World! \t\n", " \t\n");
    printf("Trim whitespace: '%s'\n", result);
    free(result);
    
    result = ft_strtrim(NULL, " ");
    printf("S1 NUll input: '%s'\n", result);
    free(result);

    result = ft_strtrim("Hello, World!", NULL);
    printf("Null input to trim: '%s'\n", result); 
    free(result);

	result = ft_strtrim(NULL, NULL);
	printf("Null both: '%s'\n", result);
	free(result);

	return (0);
*/
