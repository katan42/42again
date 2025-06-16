/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 20:53:36 by ka-tan            #+#    #+#             */
/*   Updated: 2025/05/27 19:26:58 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	if (!lst)
		return (NULL);
	current = lst;
	while (current->next != NULL)
	{
		current = current->next;
	}
	return (current);
}
// int main(void)
// {
// 	int a = 42;
// 	int b = 99;
// 	int c = 123;

// 	t_list	*head = ft_lstnew(&a);
// 	t_list	*first = ft_lstnew(&b);
// 	t_list	*second = ft_lstnew(&c);

// 	head->next = first;
// 	first->next = second;

// 	t_list	*last = ft_lstlast(head);

// 	printf("last node: %d\n", *(int *)last->content);
// 	free(head);
// 	free(first);
// 	free(second);
// }