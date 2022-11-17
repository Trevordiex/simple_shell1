#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * env - prints the current environment
 * @env: the environment of the current process
 *
 * Return: void
 */
void env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		print("%s\n", env[i]);
	}
}

/**
 * _exit_ - termiates the calling process normally
 * @env: the environment of the current process
 *
 * Return: void
 */
void _exit_(char **env)
{
	env++;
	exit(0);
}

/**
 * get_builtin - get a pointer to the function corresponding to name
 * @name: the name of the function from the env_builtin struct
 *
 * Return: returns a function pointer if exists or NULL
 */
cmd get_builtin(char *name)
{
	env_builtin builtins[] = {
		{"env", env},
		{"exit", _exit_}
	};
	env_builtin command;

	int i, len;

	len = sizeof(builtins) / sizeof(builtins[0]);
	for (i = 0; i < len; i++)
	{
		command = builtins[i];
		if (is_equal(name, command.name))
			return (command.cmd);
	}

	return (NULL);

}
