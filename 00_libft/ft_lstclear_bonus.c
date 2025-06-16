/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 20:53:23 by ka-tan            #+#    #+#             */
/*   Updated: 2025/06/06 23:00:34 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//go to node, delete with fn pointer then move to next 
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}
// void	del(void *content)
// {
// 	free(content);
// }
// int main(void)
// {
// 	int *a = malloc(sizeof(int));
// 	int *b = malloc(sizeof(int));
// 	int *c = malloc(sizeof(int));

// 	*a = 42;
// 	*b = 99;
// 	*c = 78;

// 	t_list	*head = ft_lstnew(a);
// 	t_list	*first = ft_lstnew(b);
// 	t_list	*second = ft_lstnew(c);

// 	head->next = first;
// 	first->next = second;

// 	t_list *current = head;
// 	while (current)
// 	{
// 		printf("%d -> ", *(int*)current->content);
// 		current = current->next;
// 	}
// 	printf("NULL\n");
// 	ft_lstclear(&head, del);
// 	if (head != NULL)
// 		printf("linked list not cleared\n");
// 	else
// 		printf("linked list cleared\n");
// }