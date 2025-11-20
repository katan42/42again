/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 21:17:53 by ka-tan            #+#    #+#             */
/*   Updated: 2025/10/01 11:41:47 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_exact_line(const char *line)
{
	char	*exact_line;
	size_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	exact_line = ft_substr(line, 0, i);
	return (exact_line);
}

static char	*join_old_buf(char *old, const char *buf)
{
	char	*joined;

	joined = ft_strjoin(old, buf);
	if (old)
		free(old);
	return (joined);
}

static int	fill_line_buffer(int fd, char **left)
{
	char	*buf;
	ssize_t	r;
	char	*nl;

	nl = ft_strchr(*left, '\n');
	while (!nl)
	{
		buf = (char *)malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (-1);
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0)
			return (free(buf), -1);
		buf[r] = '\0';
		*left = join_old_buf(*left, buf);
		free(buf);
		if (!*left)
			return (-1);
		if (r == 0)
			break ;
		nl = ft_strchr(*left, '\n');
	}
	return (0);
}

static char	*set_line(char **leftover)
{
	size_t	i;
	char	*rest;

	if (!leftover || !*leftover)
		return (NULL);
	i = 0;
	while ((*leftover)[i] && (*leftover)[i] != '\n')
		i++;
	if ((*leftover)[i] == '\n')
		i++;
	rest = ft_substr(*leftover, i, ft_strlen(*leftover + i));
	free(*leftover);
	*leftover = rest;
	return (*leftover);
}

char	*get_next_line(int fd)
{
	static char	*left;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!left)
		left = ft_strdup("");
	if (!left)
		return (NULL);
	if (fill_line_buffer(fd, &left) == -1)
		return (free(left), left = NULL, NULL);
	if (left[0] == '\0')
		return (free(left), left = NULL, NULL);
	line = get_exact_line(left);
	set_line(&left);
	if (!line)
		return (free(left), left = NULL, NULL);
	return (line);
}
