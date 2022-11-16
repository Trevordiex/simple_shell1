#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include "main.h"

/**
 * run_command - execs a command and returns
 * @exec_name: the string passed as argv[0]
 * @line: the string containing the command to execute
 *
 * Return: 1 if execution is successful and 0 if successful with EOF else -1
 */
int run_command(const char *exec_name, const char *line)
{
	pid_t child_pid;
	char **vargs, **tokens, *command;
	int status, argc;
	path_t **paths, *path;

	vargs = str_tok((char *) line, " ");
	if (!vargs)
		return (0);

	command = _which(vargs[0]);
	if (!command)
	{
		print("%s: command not found\n", vargs[0]);
		return (1);
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
	}
	if (child_pid == 0)
	{
		if (execve(command, vargs, NULL) == -1)
		{
			perror(exec_name);
		}
		exit(0);
	}
	else
	{
		wait(&status);
	}
	return (1);
}
