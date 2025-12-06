/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 22:15:18 by ka-tan            #+#    #+#             */
/*   Updated: 2025/11/22 22:15:37 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
// rr : ra and rb at the same time.

void	rotate(t_stack *stack)
{
	t_norm	temp;
	int		i;

	i = 0;
	temp = stack->array[i];
	while (i < stack->size - 1)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->array[i] = temp;
}

void	rotate_a(t_stack *stack_a)
{
	if (stack_a->size > 1)
	{
		rotate(stack_a);
		write(1, "ra\n", 3);
	}
}

void	rotate_b(t_stack *stack_b)
{
	if (stack_b->size > 1)
	{
		rotate(stack_b);
		write(1, "rb\n", 3);
	}
}

void	rotate_a_and_b(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size > 1 && stack_b->size > 1)
	{
		rotate(stack_a);
		rotate(stack_b);
		write(1, "rr\n", 3);
	}
}
