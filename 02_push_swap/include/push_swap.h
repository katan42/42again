/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:44:22 by ka-tan            #+#    #+#             */
/*   Updated: 2025/11/22 22:29:00 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_norm
{
	int	value;
	int	norm;
}	t_norm;

typedef struct s_stack
{
	t_norm	*array;
	int		size;
}	t_stack;

t_stack	*init_stack(int capacity);
t_stack	*init_stacks(int capacity, t_stack **stack_a,
			t_stack **stack_b, char **argv);
int		check_duplicates(char **argv, int size);
int		check_num(char const *str);
int		validate_input(char *str);
void	normalise_values(t_stack *stack_a);

//operations
void	push(t_stack *stack_1, t_stack *stack_2);
void	push_a(t_stack *stack_a, t_stack *stack_b);
void	push_b(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate(t_stack *stack);
void	reverse_rotate_a(t_stack *stack_a);
void	reverse_rotate_b(t_stack *stack_b);
void	reverse_rotate_a_and_b(t_stack *stack_a, t_stack *stack_b);
void	rotate(t_stack *stack);
void	rotate_a(t_stack *stack_a);
void	rotate_b(t_stack *stack_b);
void	rotate_a_and_b(t_stack *stack_a, t_stack *stack_b);
void	swap(t_stack *stack);
void	swap_a(t_stack *stack_a);
void	swap_b(t_stack *stack_b);
void	swap_a_b(t_stack *stack_a, t_stack *stack_b);

//sort
void	sort_three(t_stack *stack_a);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
void	radix_sort(t_stack *stack_a, t_stack *stack_b);
int		sort_menu(t_stack *stack_a, t_stack *stack_b, int count);
int		sort_check(t_stack *stack_a);

//error msg
void	free_stack(t_stack *stack);
int		free_everything(t_stack *stack_a, t_stack *stack_b);
int		error_exit(t_stack **stack_a, t_stack **stack_b);
#endif
