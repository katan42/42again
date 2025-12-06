/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 22:07:28 by ka-tan            #+#    #+#             */
/*   Updated: 2025/12/02 19:23:02 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(int capacity)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->array = malloc(sizeof(t_norm) * capacity);
	if (!stack->array)
	{
		free(stack);
		return (NULL);
	}
	stack->size = 0;
	return (stack);
}

t_stack	*init_stacks(int capacity, t_stack **stack_a,
			t_stack **stack_b, char **argv)
{
	int	i;

	*stack_a = init_stack(capacity);
	if (!*stack_a)
		return (NULL);
	*stack_b = init_stack(capacity);
	if (!*stack_b)
		return (free(*stack_a), NULL);
	if (check_duplicates(argv, capacity))
		return (error_exit(stack_a, stack_b), NULL);
	i = 0;
	while (i < capacity)
	{
		if (!validate_input(argv[i + 1]))
			return (error_exit(stack_a, stack_b), NULL);
		(*stack_a)->array[i].value = ft_atoi(argv[i + 1]);
		(*stack_a)->size++;
		i++;
	}
	return (*stack_a);
}
