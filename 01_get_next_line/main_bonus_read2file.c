#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(int ac, char **av)
{
	int   fd1, fd2;
	char *l1, *l2;
	int   step;

	if (ac < 3)
	{
		printf("usage: %s fileA fileB\n", av[0]);
		return (0);
	}
	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
	{
		perror("open");
		if (fd1 >= 0) close(fd1);
		if (fd2 >= 0) close(fd2);
		return (1);
	}
	step = 1;
	l1 = get_next_line(fd1);
	l2 = get_next_line(fd2);
	while (l1 || l2)
	{
		if (l1)
		{
			printf("A%02d: %s", step, l1);
			free(l1);
			l1 = get_next_line(fd1);
		}
		if (l2)
		{
			printf("B%02d: %s", step, l2);
			free(l2);
			l2 = get_next_line(fd2);
		}
		step++;
	}
	close(fd1);
	close(fd2);
	return (0);
}
