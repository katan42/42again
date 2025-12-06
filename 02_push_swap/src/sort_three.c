/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 22:13:38 by ka-tan            #+#    #+#             */
/*   Updated: 2025/11/22 22:13:48 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	if (a->array[0].norm < a->array[1].norm && a->array[1].norm
		> a->array[2].norm && a->array[0].norm < a->array[2].norm)
	{
		reverse_rotate_a(a);
		swap_a(a);
	}
	else if (a->array[0].norm > a->array[1].norm && a->array[1].norm
		< a->array[2].norm && a->array[0].norm < a->array[2].norm)
		swap_a(a);
	else if (a->array[0].norm < a->array[1].norm && a->array[1].norm
		> a->array[2].norm && a->array[2].norm < a->array[0].norm)
		reverse_rotate_a(a);
	else if (a->array[0].norm > a->array[1].norm && a->array[0].norm
		> a->array[2].norm && a->array[1].norm < a->array[2].norm)
		rotate_a(a);
	else if (a->array[0].norm > a->array[1].norm && a->array[0].norm
		> a->array[2].norm && a->array[1].norm > a->array[2].norm)
	{
		swap_a(a);
		reverse_rotate_a(a);
	}
}
