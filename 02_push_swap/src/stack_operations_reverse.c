/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_reverse.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 22:15:09 by ka-tan            #+#    #+#             */
/*   Updated: 2025/11/22 22:24:22 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
// rrr : rra and rrb at the same time.

void	reverse_rotate(t_stack *stack)
{
	t_norm	temp;
	int		i;

	i = stack->size - 1;
	temp = stack->array[i];
	while (i > 0)
	{
		stack->array[i] = stack->array[i - 1];
		i--;
	}
	stack->array[0] = temp;
}

void	reverse_rotate_a(t_stack *stack_a)
{
	if (stack_a->size > 1)
	{
		reverse_rotate(stack_a);
		write(1, "rra\n", 4);
	}
}

void	reverse_rotate_b(t_stack *stack_b)
{
	if (stack_b->size > 1)
	{
		reverse_rotate(stack_b);
		write(1, "rrb\n", 4);
	}
}

void	reverse_rotate_a_and_b(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size > 1 && stack_b->size > 1)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
		write(1, "rrr\n", 4);
	}
}
