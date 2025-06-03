/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 20:53:28 by ka-tan            #+#    #+#             */
/*   Updated: 2025/06/03 16:56:24 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
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
// 	head->next = first->next;
// 	ft_lstdelone(first, del);
// 	while (head)
// 	{
// 		printf("%d -> ", *(int*)head->content);
// 		head = head->next;
// 	}
// 	free(head);
// 	free(second);
// }
