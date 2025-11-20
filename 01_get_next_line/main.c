#include <fcntl.h>     
#include <unistd.h>    
#include <stdio.h>     
#include <stdlib.h>    
#include "get_next_line.h"

int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		i;

	if (ac == 1)
	{
		fd = 0;
		write(2, "type your input\n", 16);
	}
	else if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
	}
	else 
	{
		write(2, "Usage: ./a.out <file>\n", 23);
		return (1);
	}
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	i = 1;
	line = get_next_line(fd);
	while (line)
	{
		printf("%02d: %s", i, line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}