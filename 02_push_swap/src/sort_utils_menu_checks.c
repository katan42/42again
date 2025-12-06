/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_menu_checks.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 22:14:01 by ka-tan            #+#    #+#             */
/*   Updated: 2025/11/22 22:14:17 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_menu(t_stack *stack_a, t_stack *stack_b, int count)
{
	if (count == 1)
		return (1);
	else if (count == 2)
		swap_a(stack_a);
	else if (count == 3)
		sort_three(stack_a);
	else if (count == 5)
		sort_five(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
	return (0);
}

int	sort_check(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (i < stack_a->size - 1)
	{
		if (stack_a->array[i].norm > stack_a->array[i + 1].norm)
			return (0);
		i++;
	}
	return (1);
}
