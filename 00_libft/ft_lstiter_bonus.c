/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:58:37 by ka-tan            #+#    #+#             */
/*   Updated: 2025/06/06 23:00:16 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
// void f(void	*content)
// {
// 	printf("%d\n", *(int *)content);
// }
// void	del(void *content)
// {
// 	free(content);
// }

// void	ft_lstclear(t_list **lst, void (*del)(void*))
// {
// 	t_list	*temp;

// 	if (!lst || !*lst || !del)
// 		return ;
// 	while (*lst)
// 	{
// 		temp = (*lst)->next;
// 		del((*lst)->content);
// 		free(*lst);
// 		*lst = temp;
// 	}
// 	*lst = NULL;
// }

// int main (void)
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
// 	ft_lstiter(head,f);
// 	ft_lstclear(&head, del);
// }