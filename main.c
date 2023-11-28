#include <fcntl.h>
#include <stdio.h>
#include "get_next_line_bonus.h"

int main(void)
{
	char    *line;
	int		i = 1;
	int		fd1 = 0;
	int		fd2 = 0;
	int		fd3 = 0;

	fd1 = open("tests/test1.txt", O_RDONLY);
	fd1 = open("tests/test2.txt", O_RDONLY);
	fd1 = open("tests/test3.txt", O_RDONLY);

	while (i < 7)
	{
		line = get_next_line_bonus(fd1);
		printf("line [%02d], fichier 1 : %s\n", i, line);
		free (line);
		line = get_next_line_bonus(fd2);
		printf("line [%02d], fichier 2 : %s\n", i, line);
		free (line);
		line = get_next_line_bonus(fd3);
		printf("line [%02d], fichier 3 : %s\n", i, line);
		free (line);
		i++;
	}
	close (fd1);
	close (fd2);
	close (fd3);
	return (0);
}