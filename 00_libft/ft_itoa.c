/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 21:14:23 by ka-tan            #+#    #+#             */
/*   Updated: 2025/06/12 19:14:20 by ka-tan           ###   ########.fr       */
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

// int	main(void) 
// {
// 	int num = -2147483648;
// 	char* str = ft_itoa(num);
// 	if (str)
// 	{
// 		printf("itoa: %d -> %s\n", num, str);
// 	} 
// 	else
// 	{
// 		printf("Memory allocation failed!\n");
// 	}
// 	free(str);
// 	return (0);
// }