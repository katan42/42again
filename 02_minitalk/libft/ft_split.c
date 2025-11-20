/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 21:13:50 by ka-tan            #+#    #+#             */
/*   Updated: 2025/06/15 18:25:59 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wordcount(char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*alloc_mem_word(char *s1, char c, size_t len)
{
	char	*s2;

	if (!ft_memchr(s1, c, len))
		s2 = malloc(len + 1);
	else
		s2 = malloc((char *)ft_memchr(s1, c, len) - s1 + 1);
	if (!s2)
		return (NULL);
	return (s2);
}

static char	**free_dptr(char **dptr, size_t j)
{
	size_t	i;

	i = 0;
	while (i <= j)
		free(dptr[i++]);
	free(dptr);
	return (NULL);
}

static int	copystr(char **dptr, char *s1, char c, size_t *j)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	while (*s1)
	{
		while (*s1 && *s1 == c && len --)
			s1++;
		if (*s1)
		{
			*dptr = alloc_mem_word(s1, c, len);
			if (!*dptr)
				return (0);
			i = 0;
			while (*s1 && *s1 != c && len--)
				(*dptr)[i++] = *s1++;
			(*dptr++)[i] = '\0';
			(*j)++;
		}
	}
	*dptr = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char			**dptr;
	char			**head;
	char			*s1;
	size_t			j;

	s1 = (char *)s;
	j = 0;
	head = (char **)malloc((wordcount((char *)s, c) + 1) * sizeof(char *));
	if (!head)
		return (NULL);
	dptr = head;
	if (!copystr(dptr, s1, c, &j))
		return (free_dptr(dptr, j));
	return (head);
}

// int main(void)
// {
// 	char **result;
// 	char *str = "hello world this is ft_split finally!";
// 	char delimiter = ' ';
// 	int i;

// 	result = ft_split(str, delimiter);

// 	if (result)
// 	{
// 		i = 0;
// 		while (result[i] != NULL)
// 		{
// 			printf("Word %d: %s\n", i + 1, result[i]);
// 			free(result[i]);
// 			i++;
// 		}
// 		free(result);
// 	}
// 	else
// 	{
// 		printf("Memory allocation failed or no words found.\n");
// 	}

// 	return 0;
// }