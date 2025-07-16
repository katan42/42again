/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 22:13:09 by ka-tan            #+#    #+#             */
/*   Updated: 2025/07/10 18:09:59 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <limits.h>

// int main(void)
// {
// 	int i = 5;
// 	int j = -2;
// 	// char c = 'a';
// 	// char str = NULL;
	
// 	printf("i using specifier d is %d\n", i);
// 	printf("i using specifier i is %i\n", i);
// 	printf("i using specifier u is %u\n", i);
// 	printf("j using specifier d is %d\n", j);
// 	printf("j using specifier i is %i\n", j);
// 	printf("j using specifier i is %u\n", j);
// 	// printf("%%");
// 	// printf("\n");
// 	// printf("%%%");
// 	// printf("\n");
// 	// printf("%%%%");
// 	// printf("%q");
// 	// printf("%s", str);
// }
//to type in terminal
// cc -Wall -Wextra -Werror main.c libftprintf.a -Iinclude -o test

#include <stdio.h>
#include <limits.h>


int	main(void)
{
	int	ret1, ret2;
	int	x = 42;
	char	*str = "Hello";

	printf("========== ft_printf vs printf Tests ==========\n\n");

	// Test 1: Character
	printf("[Char Test]\n");
	ret1 = ft_printf("ft_printf: %c\n", 'A');
	ret2 = printf("   printf: %c\n", 'A');
	printf("Return: ft = %d, printf = %d\n\n", ret1, ret2);

	// Test 2: String
	printf("[String Test]\n");
	ret1 = ft_printf("ft_printf: %s\n", str);
	ret2 = printf("   printf: %s\n", str);
	printf("Return: ft = %d, printf = %d\n\n", ret1, ret2);

	// Test 3: NULL string
	printf("[NULL String Test]\n");
	ret1 = ft_printf("ft_printf: %s\n", (char *)NULL);
	ret2 = printf("   printf: %s\n", (char *)NULL);
	printf("Return: ft = %d, printf = %d\n\n", ret1, ret2);

	// Test 4: Pointer
	printf("[Pointer Test]\n");
	ret1 = ft_printf("ft_printf: %p\n", &x);
	ret2 = printf("   printf: %p\n", &x);
	printf("Return: ft = %d, printf = %d\n\n", ret1, ret2);

	// Test 5: NULL pointer
	printf("[NULL Pointer Test]\n");
	ret1 = ft_printf("ft_printf: %p\n", NULL);
	ret2 = printf("   printf: %p\n", NULL);
	printf("Return: ft = %d, printf = %d\n\n", ret1, ret2);

	// Test 6: Signed Ints
	printf("[Signed Int Test]\n");
	ret1 = ft_printf("ft_printf: %d %i\n", -1234, 5678);
	ret2 = printf("   printf: %d %i\n", -1234, 5678);
	printf("Return: ft = %d, printf = %d\n\n", ret1, ret2);

	// Test 7: INT Min/Max
	printf("[INT Min/Max Test]\n");
	ret1 = ft_printf("ft_printf: %d %d\n", INT_MIN, INT_MAX);
	ret2 = printf("   printf: %d %d\n", INT_MIN, INT_MAX);
	printf("Return: ft = %d, printf = %d\n\n", ret1, ret2);

	// Test 8: Unsigned Int
	printf("[Unsigned Test]\n");
	ret1 = ft_printf("ft_printf: %u\n", 4294967295u); // UINT_MAX
	ret2 = printf("   printf: %u\n", 4294967295u);
	printf("Return: ft = %d, printf = %d\n\n", ret1, ret2);

	// Test 9: Hexadecimal lower/upper
	printf("[Hex Test]\n");
	ret1 = ft_printf("ft_printf: %x %X\n", 255, 255);
	ret2 = printf("   printf: %x %X\n", 255, 255);
	printf("Return: ft = %d, printf = %d\n\n", ret1, ret2);

	// Test 10: Zero values
	printf("[Zero Test]\n");
	ret1 = ft_printf("ft_printf: %d %u %x %p\n", 0, 0, 0, NULL);
	ret2 = printf("   printf: %d %u %x %p\n", 0, 0, 0, NULL);
	printf("Return: ft = %d, printf = %d\n\n", ret1, ret2);

	// Test 11: Percent symbol
	printf("[Percent Symbol Test]\n");
	ret1 = ft_printf("ft_printf: %%\n");
	ret2 = printf("   printf: %%\n");
	printf("Return: ft = %d, printf = %d\n\n", ret1, ret2);

	// Test 12: Mixed types
	printf("[Mixed Test]\n");
	ret1 = ft_printf("ft_printf: %c %s %p %d %i %u %x %X %%\n",
		'Z', "Mix", &x, -42, 42, 12345, 255, 255);
	ret2 = printf("   printf: %c %s %p %d %i %u %x %X %%\n",
		'Z', "Mix", &x, -42, 42, 12345, 255, 255);
	printf("Return: ft = %d, printf = %d\n\n", ret1, ret2);

	printf("========== End of Tests ==========\n");
	return (0);
}
