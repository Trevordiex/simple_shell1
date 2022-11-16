#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * print - checks for a string in an array.
 * @string: the format string.
 * @sub: the string to substitute.
 *
 * Return: number of characters printed.
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

/**
 * itos - prints out a number as a sequence of characters
 * @n: the number to print
 * @c: the count of characters printed
 *
 * Return: c else exit with error code 50
 */
void itos(int n)
{
	int i;
	char ch[2];

	if (n < 0)
	{
		i = write(1, "-", 1);
		if (i < 0)
		{
			write(2, "Error: write failed\n", 20);
			exit(50);
		}

		itos(-n);
	}
	else
	{
		if (n > 10)
			itos(n / 10);

		ch[0] = '0' + (n % 10);
		ch[1] = '\0';
		i = write(1, ch, 1);
		if (i < 0)
		{
			write(2, "Error: write failed\n", 20);
			exit(50);
		}
	}
}
