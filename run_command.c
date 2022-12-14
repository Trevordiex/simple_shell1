#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include "main.h"

/**
 * run_command - execs a command and returns
 * @exec_name: the string passed as argv[0]
 * @line: the string containing the command to execute
 * @env: the environment of the current process
 *
 * Return: 1 if execution is successful and 0 if successful with EOF else -1
 */
int run_command(const char *exec_name, const char *line, char **env)
{
	pid_t child_pid;
	char **vargs, *command;
	int status;

	vargs = str_tok((char *) line, " \n\t");
	if (!vargs)
		return (0);

	command = _which(vargs[0]);
	if (!command)
	{
		perror(exec_name);
		return (1);
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
	}
	if (child_pid == 0)
	{
		if (execve(command, vargs, env) == -1)
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
