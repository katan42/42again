#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

#include "get_next_line_bonus.h"

int main(int argc, char **argv)
{
    int     i;
    int     fd[1024];
    char    *line;
    int     finished;

    if (argc < 2)
        return (0);
    i = 1;
    while (i < argc)
    {
        fd[i - 1] = open(argv[i], O_RDONLY);
        if (fd[i - 1] < 0)
            return (perror("open"), 1);
        i++;
    }
    finished = 0;
    while (!finished)
    {
        finished = 1;
        i = 0;
        while (i < argc - 1)
        {
            line = get_next_line(fd[i]);
            if (line)
            {
                finished = 0;
                printf("fd[%d]: %s", fd[i], line);
                free(line);
            }
            i++;
        }
    }
    i = 0;
    while (i < argc - 1)
        close(fd[i++]);
    return (0);
}

