/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 22:13:10 by ka-tan            #+#    #+#             */
/*   Updated: 2025/12/02 17:35:52 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bits;
	int	bit;
	int	i;
	int	size;

	max_bits = 0;
	size = stack_a->size;
	while ((size - 1) >> max_bits)
		max_bits++;
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (!(stack_a->array[0].norm >> bit & 1))
				push_b(stack_a, stack_b);
			else
				rotate_a(stack_a);
			i++;
		}
		while (stack_b->size > 0)
			push_a(stack_a, stack_b);
		bit++;
	}
}
