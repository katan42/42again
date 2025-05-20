/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 20:53:59 by ka-tan            #+#    #+#             */
/*   Updated: 2025/05/20 16:48:07 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;

	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

int main(void)
{
	int a = 42;
	int b = 99;
	int c = 123;

	t_list	*head = ft_lstnew(&a);
	t_list	*first = ft_lstnew(&b);
	t_list	*second = ft_lstnew(&c);
	
	head->next = first;
	first->next = second;

	printf("size of linked list: %d\n", ft_lstsize(head));
	free(head);
	free(first);
	free(second);
}