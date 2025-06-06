/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 20:53:42 by ka-tan            #+#    #+#             */
/*   Updated: 2025/06/06 22:59:50 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

// void	del(void *content)
// {
// 	free(content);
// }

// void	*f(void *content)
// {
// 	int	*new = malloc(sizeof(int));

// 	if (!new)
// 		return (NULL);
// 	*new = 2 * (*(int *)content); 
// 	return (new);
// }

// int main(void)
// {
// 	int *a = malloc(sizeof(int));
// 	int *b = malloc(sizeof(int));
// 	int *c = malloc(sizeof(int));

// 	if (!a || !b || !c)
// 		return (write(1,"malloc failed\n", 14), 1);
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
// 	printf("NULL\n\n");
// 	t_list *new_list = ft_lstmap(head,f,del);
// 	current = new_list;
// 	while (current)
// 	{
// 		printf("%d -> ", *(int*)current->content);
// 		current = current ->next;
// 	}
// 	printf("NULL\n");
// 	ft_lstclear(&new_list, del);
// 	ft_lstclear(&head, del);

// }