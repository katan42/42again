/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 20:53:46 by ka-tan            #+#    #+#             */
/*   Updated: 2025/05/19 19:20:04 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates memory (using malloc(3)) and returns
// a new node. The ’content’ member variable is
// initialized with the given parameter ’content’.
// The variable ’next’ is initialized to NULL.

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
// int main(void)
// {
// 	int value = 42;
// 	t_list	*node = ft_lstnew(&value);

//     if (node)
//     {
//         printf("Node created!\n");
//         printf("Content: %d\n", *(int *)(node->content));
//         printf("Next: %p\n", (void *)node->next);
//     }
//     else
//     {
//         printf("Failed to create node.\n");
//     }

//     free(node);
//     return 0;
// }
