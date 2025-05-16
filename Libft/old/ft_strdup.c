/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katan <katan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:18:04 by katan             #+#    #+#             */
/*   Updated: 2024/06/24 22:27:10 by katan            ###   ########.fr       */
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
