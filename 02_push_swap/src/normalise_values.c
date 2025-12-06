/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalise_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 22:12:15 by ka-tan            #+#    #+#             */
/*   Updated: 2025/12/02 17:50:54 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	normalise_values(t_stack *stack_a)
{
	int	i;
	int	j;
	int	pos;

	i = 0;
	while (i < stack_a->size)
	{
		pos = 0;
		j = 0;
		while (j < stack_a->size)
		{
			if (stack_a->array[i].value > stack_a->array[j].value)
				pos++;
			j++;
		}
		stack_a->array[i].norm = pos;
		i++;
	}
}
