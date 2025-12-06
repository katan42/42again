/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_swap.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 22:15:58 by ka-tan            #+#    #+#             */
/*   Updated: 2025/11/22 22:22:13 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
// ss : sa and sb at the same time.

void	swap(t_stack *stack)
{
	t_norm	temp;

	temp = stack->array[0];
	stack->array[0] = stack->array[1];
	stack->array[1] = temp;
}

void	swap_a(t_stack *stack_a)
{
	if (stack_a->size > 1)
	{
		swap(stack_a);
		write(1, "sa\n", 3);
	}
}

void	swap_b(t_stack *stack_b)
{
	if (stack_b->size > 1)
	{
		swap(stack_b);
		write(1, "sb\n", 3);
	}
}

void	swap_a_b(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size > 1 && stack_a->size > 1)
	{
		swap(stack_a);
		swap(stack_b);
		write(1, "ss\n", 3);
	}
}
