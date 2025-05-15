/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katan <katan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:28:52 by katan             #+#    #+#             */
/*   Updated: 2024/06/24 22:22:09 by katan            ###   ########.fr       */
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
