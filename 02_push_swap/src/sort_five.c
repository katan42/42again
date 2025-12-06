/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 22:12:45 by ka-tan            #+#    #+#             */
/*   Updated: 2025/12/02 17:34:21 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->array[0].norm > 1)
	{
		rotate_a(stack_a);
	}
	push_b(stack_a, stack_b);
	while (stack_a->array[0].norm > 1)
	{
		rotate_a(stack_a);
	}
	push_b(stack_a, stack_b);
	sort_three(stack_a);
	if (stack_b->array[0].norm < stack_b->array[1].norm)
		swap_b(stack_b);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}
