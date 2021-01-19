#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	char *line;
	int fd = open("file", O_RDONLY);
	printf("%d\n", get_next_line(fd, &line));
}
