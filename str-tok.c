#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * str_tok - splits a string into an tokens at delimiter and return array
 * @str: the string to split
 * @sep: the delimiter string
 *
 * Return: pointer to string array or NULL
 */
char **str_tok(char *str, char *sep)
{
	char *line;
	char **tokens, *token;
	int i, size;
	size_t len;

	size = 5;
	i = 0;

	len = _strlen(str);
	line = malloc(sizeof(*line) * (len + 1));
	tokens = malloc(sizeof(char *) * size);
	if (!tokens || !line)
		return (NULL);

	line = _memcpy(line, str, len);
	line[len] = '\0';
	token = strtok(line, sep);
	while (token)
	{
		tokens[i] = token;
		i++;
		token = strtok(0, sep);

		if (size - 1 <= i)
		{
			size *= 2;
			tokens = realloc(tokens, sizeof(char *) * size);
		}
	}
	tokens[i] = NULL;

	return (tokens);
}
