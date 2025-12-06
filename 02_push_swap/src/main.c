/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 22:11:57 by ka-tan            #+#    #+#             */
/*   Updated: 2025/11/22 22:23:46 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		count;

	if (argc < 2)
		return (0);
	if (argc == 2 && argv[1][0] == '\0')
		return (write(2, "Error\n", 6), 1);
	count = argc - 1;
	if (!init_stacks(count, &stack_a, &stack_b, argv))
		error_exit(&stack_a, &stack_b);
	normalise_values(stack_a);
	if (!sort_check(stack_a))
		sort_menu(stack_a, stack_b, count);
	free_everything(stack_a, stack_b);
	return (0);
}
