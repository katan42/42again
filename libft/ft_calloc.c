/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:42:37 by ka-tan            #+#    #+#             */
/*   Updated: 2025/06/07 16:06:42 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	if (nmemb == 0 || size == 0)
		return (malloc(1));
	total = nmemb * size;
	if (nmemb != 0 && total / nmemb != size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}

// int main(void)
// {
// 	size_t num_elements = 5;
// 	int *array = (int *)ft_calloc(num_elements, sizeof(int));
// 	size_t i = 0; 
// 	if (array == NULL)
// 	{
// 		printf("Memory allocation failed.\n");
// 		return 1;
// 	}
//     while (i < num_elements) 
// 	{
// 		i++;
// 		printf("array[%zu] = %d\n", i, array[i]);
//     }
//     free(array);
//     return 0;
// }