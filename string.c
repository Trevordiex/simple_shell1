#include <string.h>
#include <stdlib.h>
#include "main.h"

/**
 * _memcpy - copies a characters from src memory area to target mem area
 * @dest: destination mem area
 * @src: source mem area
 * @n: number of characters to copy
 *
 * Return: returns thea address of dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *tmp;

	tmp = dest;
	while (n--)
		*tmp++ = *src++;

	return (dest);
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

	len = _strlen(str);
	line = malloc(sizeof(*line) * len + 1);
	if (!line)
		return (NULL);

	_memcpy(line, str, len);
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


/**
 * _strlen - calculates the length of a string
 * @str: the string to calculate the length
 *
 * Return: returns the length of the string
 */

size_t _strlen(char *str)
{
	size_t length;

	length = 0;
	while (*str)
	{
		length++;
		str++;
	}

	return (length);
}

