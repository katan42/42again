/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 21:12:36 by ka-tan            #+#    #+#             */
/*   Updated: 2025/05/16 21:12:39 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	sublen;
	char	*str;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	sublen = slen - start;
	if (len > sublen)
		len = sublen;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
/*
int main(void) 
{
	const char* text = "Hello, world!";
	int start = 0;
	int length = 5;

	char* result = ft_substr("tripouille", 0, 42000);
	if (result != NULL) {
	printf("Substring: %s\n", result);
	free(result); // Free the allocated memory
	} else {
	printf("Invalid substring parameters.\n");
	}
    return 0;
}
*/