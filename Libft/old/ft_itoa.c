/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katan <katan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 22:22:06 by katan             #+#    #+#             */
/*   Updated: 2024/06/23 23:43:04 by katan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	num_length(int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i = i + 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	number;
	unsigned int	length;

	length = num_length(n);
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		number = -n;
	}
	else
		number = n;
	if (number == 0)
		str[0] = '0';
	str[length] = '\0';
	while (number != 0)
	{
		str[length - 1] = (number % 10 + '0');
		number = number / 10;
		length--;
	}
	return (str);
}
/*
int	main(void) 
{
	// Integer to String
	int num = -2147483648;
	char* str = ft_itoa(num);
	if (str)
	{
    	printf("itoa: %d -> %s\n", num, str);
    } 
	else
	{
    	printf("Memory allocation failed!\n");
	}
    // Freeing allocated memory for the string
	free(str);

	return (0);
}
*/
