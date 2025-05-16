/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katan <katan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 22:18:54 by katan             #+#    #+#             */
/*   Updated: 2024/06/24 19:37:27 by katan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	wordcount(char *s, char c)
{
	int	count;

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

static char	*alloc_mem_word(char *s1, char c, unsigned int len)
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

static char	**free_dptr(char **dptr, unsigned int j)
{
	unsigned int	i;

	i = 0;
	while (i <= j)
		free(dptr[i++]);
	free(dptr);
	return (NULL);
}

static int	copystr(char **dptr, char *s1, char c, unsigned int *j)
{
	unsigned int	len;
	unsigned int	i;

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
	unsigned int	j;

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
/*
int main(void)
{
    char **result;
    char *str = "hello world this is ft_split finally!";
    char delimiter = ' ';
    int i;

    result = ft_split(str, delimiter);

    if (result)
    {
        for (i = 0; result[i] != NULL; i++)
        {
            printf("Word %d: %s\n", i + 1, result[i]);
            free(result[i]);  // Free the mem for each word
        }
        free(result);  // Free the pointers
    }
    else
    {
        printf("Memory allocation failed or no words found.\n");
    }

    return 0;
}
*/
