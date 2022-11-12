#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include "main.h"

/**
 * _which - returns the path of first file that exist on PATH
 * @bin: the binary to search for
 *
 * Description: if bin is absolute path, return bin else search path
 * Return: pointer to path string or NULL
 */
char *_which(char *bin)
{
	path_t *path;
	char *filename;
	size_t len;
	struct stat st;

	if (bin[0] == '/')
	{
		if (stat(bin, &st) == 0)
		{
			return (malloc_str(bin));
		}
		else
		{
			perror(bin);
			return (NULL);
		}
	}
	else
	{
		path = build_path_list();
		if (!path)
		{
			printf("couldnt build path list\n");
			exit(1);
		}
		while (path->next)
		{
			len = strlen(path->path) + strlen(bin) + 2;
			filename = malloc(sizeof(*filename) * len);
			memcpy(filename, path->path, strlen(path->path));
			strcat(filename, "/");
			strcat(filename, bin);
			filename[len] = '\0';

			if (stat(filename, &st) == 0)
				return (filename);
			else
				free(filename);

			path = path->next;
		}
		return (NULL);
	}
}
