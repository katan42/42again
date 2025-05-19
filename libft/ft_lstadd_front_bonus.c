/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 20:53:19 by ka-tan            #+#    #+#             */
/*   Updated: 2025/05/19 19:19:51 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
// int main(void)
// {
// 	int a = 42;
// 	int b = 99;

// 	t_list	*head = NULL;
// 	t_list	*first = ft_lstnew(&a);
// 	t_list	*second = ft_lstnew(&b);

// 	ft_lstadd_front(&head, first);
// 	ft_lstadd_front(&head, second);

// 	printf("First content: %d\n", *(int *)(head->content));           // 99
//     printf("Second content: %d\n", *(int *)(head->next->content));    // 42

// 	free(first);
// 	free(second);

// 	return (0);
// }
