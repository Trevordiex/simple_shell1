#include <stdlib.c>
#include "main.h"

int main(int argc, char **argv)
{
	char *file;

	if (argc != 2)
	{
		printf("Usage: %s file\n", argv[0]);
		exit(1);
	}
	file = _which(argv[1]);
	if (file)
		printf("%s\n", file);
		free(file);

	return (0);
}