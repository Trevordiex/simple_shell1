#include <unistd.h>
#include "main.h"

/**
 * print - checks for a string in an array
 * @string: the format string
 * @sub: the string to substitute
 *
 * Return: number of characters printed
 */

int print(char *string, char *sub)
{
	int i;
	char c;

	for (i = 0; (c = string[i]) != '\0'; i++)
	{
		if ((c == '%') && (string[i + 1] == 's'))
		{
			write(1, sub, _strlen(sub));
			i++;
			continue;
		}

		write(1, &c, 1);
	}

	return (i);
}

