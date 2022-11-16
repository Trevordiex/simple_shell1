#include <stdlib.h>
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
	size_t len, len_bin, len_path;
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
			print("couldnt build path list\n", "");
			exit(1);
		}
		while (path->next)
		{
			len_path = _strlen(path->path);
			len_bin = _strlen(bin);
			len = len_path + len_bin + 2;
			filename = malloc(sizeof(*filename) * len);
			_memcpy(filename, path->path, len_path);
			_memcpy(filename + len_path, "/", 1);
			_memcpy(filename + len_path + 1, bin, len_bin);
			filename[len] = '\0';

			if (stat(filename, &st) == 0)
				return (filename);

			free(filename);
			path = path->next;
		}
		return (NULL);
	}
}
