/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:43:05 by ka-tan            #+#    #+#             */
/*   Updated: 2025/05/16 20:34:25 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (j + 1));
	if (str == NULL)
	{
		return (NULL);
	}
	while (i < j)
	{
		str[i] = s[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}
/*
int main(void) 
{
	const char *original = "Hello, World!";
	char *duplicate = ft_strdup(original);
	// Check if duplication was successful
	if (duplicate == NULL) 
	{
	printf("Memory allocation failed.\n");
	return 1;
	}	
	// Print the duplicated string
	printf("Original: %s\n", original);
	printf("Duplicate: %s\n", duplicate);
	    
	// Free the duplicated string
	free(duplicate);
	return 0;
}
*/