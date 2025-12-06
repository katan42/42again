/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 20:52:53 by ka-tan            #+#    #+#             */
/*   Updated: 2025/05/27 19:27:19 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
//(!*lst) checks if the list is empty, not if the parameter is NULL
// int main(void)
// {
// 	int a = 42;
// 	int b = 99;
// 	int c = 123;
// 	int d = 51;

// 	t_list	*head = ft_lstnew(&a);
// 	t_list	*first = ft_lstnew(&b);
// 	t_list	*second = ft_lstnew(&c);
// 	t_list	*new = ft_lstnew(&d);

// 	head->next = first;
// 	first->next = second;

// 	t_list	*last = ft_lstlast(head);
// 	ft_lstadd_back(&head,new);
// 	printf("last node: %d\n", *(int *)new->content);
// 	free(head);
// 	free(first);
// 	free(second);
// 	free(new);
// }

//cleaner way to write main because we are adding a new node,
//linking to the next node until last node
// int main(void)
// {
// 	int a = 42;
// 	int b = 99;
// 	int c = 123;
// 	int d = 51;

// 	t_list	*head = NULL;
// 	ft_lstadd_back(&head,ft_lstnew(&a));
// 	ft_lstadd_back(&head,ft_lstnew(&b));
// 	ft_lstadd_back(&head,ft_lstnew(&c));
// 	ft_lstadd_back(&head,ft_lstnew(&d));

// 	while (head)
// 	{
// 		t_list	*temp = head->next;
// 		printf("%d -> ", *(int*)head->content);
// 		free(head);
// 		head = temp;
// 	}
// 	printf("NULL\n");
// 	return (0);
// }