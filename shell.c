#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
 * main - A super simple shell
 * @argc: the argument count
 * @argv: argument vector - array of arguments
 * @env: the current environment
 *
 * Description: runs command just as in a shell
 *
 * Return: exit status
 */
int main(int argc, char **argv, char **env)
{
	char *line = NULL;
	size_t n = 0;
	int end;
	ssize_t len;
	void (*cmd)(void);

	do {
		if (line)
		{
			if (line[len - 1] == '\n')
				line[len - 1] = '\0';

			cmd = get_builtin(line);
			if (cmd)
				(*cmd)();
			else
				run_command(argv[0], line);
		}

		if (isatty(fileno(stdin)))
			print("$ ", "");
		len = getline(&line, &n, stdin);
	} while (len != -1);

	free(line);
	exit(EXIT_SUCCESS);
}

