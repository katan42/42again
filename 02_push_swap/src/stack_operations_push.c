/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_push.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 22:14:45 by ka-tan            #+#    #+#             */
/*   Updated: 2025/11/22 22:23:11 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pa(pusha):Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
// pb(pushb):Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.

void	push(t_stack *stack_1, t_stack *stack_2)
{
	int	i;

	if (stack_2->size < 1)
		return ;
	i = stack_1->size;
	while (i > 0)
	{
		stack_1->array[i] = stack_1->array[i - 1];
		i--;
	}
	stack_1->array[0] = stack_2->array[0];
	stack_1->size++;
	i = 0;
	while (i < stack_2->size - 1)
	{
		stack_2->array[i] = stack_2->array[i + 1];
		i++;
	}
	stack_2->size--;
}

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	write(1, "pb\n", 3);
}
