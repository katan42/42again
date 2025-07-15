/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:43:05 by ka-tan            #+#    #+#             */
/*   Updated: 2025/06/12 17:48:06 by ka-tan           ###   ########.fr       */
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
		return (NULL);
	while (i < j)
	{
		str[i] = s[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}

// int main(void) 
// {
// 	const char *original = "Hello, World!";
// 	char *duplicate = ft_strdup(original);

// 	if (duplicate == NULL) 
// 	{
// 		printf("Memory allocation failed.\n");
// 		return (1);
// 	}	
// 	printf("Original: %s\n", original);
// 	printf("Duplicate: %s\n", duplicate);
// 	free(duplicate);
// 	return 0;
// }