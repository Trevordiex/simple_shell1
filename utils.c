#include <string.h>
#include <stdlib.h>
#include "main.h"

/**
 * startswith - compares two string for equality
 * @str: the string to test its prefix
 * @prefix: the prefix to test in strings
 *
 * Return: 1 if equal else 0
 */
int startswith(char *str, char *prefix)
{
	if (strncmp(prefix, str, strlen(prefix)) == 0)
		return (1);
	else
		return (0);
}

/**
 * malloc_str - creates a copy of string
 * @str: string to replicate
 *
 * Return: pointer to created string or NULL
 */
char *malloc_str(char *str)
{
	size_t len;
	char *line;

	len = strlen(str);
	line = malloc(sizeof(*line) * len + 1);
	if (!line)
		return (NULL);

	memcpy(line, str, len);
	line[len] = '\0';

	return (line);
}

/**
 * _strcmp - compares two strings
 * @s1: the address of the first string to compare
 * @s2: the address of the second string to compare
 *
 * Return: returns 0 if equal, -1 if s1 is less and 1 if s1 is greater
 */

int _strcmp(char *s1, char *s2)
{
	int i, ret;
	char c, d;

	i = 0;
	while ((c = *(s1 + i)) == (d = *(s2 + i)))
	{
		i++;
		if (c == '\0')
			return (0);
	}

	if (c < d)
		ret = -15;
	else if (c > d)
		ret = 15;

	return (ret);
}

/**
 * is_equal - checks that two strings are equally lexicographically
 * @s1: first string to compare
 * @s2: second string to compare
 *
 * Description: uses _strcmp under the hood
 * Return: 1 if both strings are equal else 0
 */
int is_equal(char *s1, char *s2)
{
	if (_strcmp(s1, s2) == 0)
		return (1);
	return (0);
}
