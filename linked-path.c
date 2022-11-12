#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * build_path_list - builds a linked list from the system path
 *
 * Return: the head of the linked list or NULL
 */

path_t *build_path_list(void)
{
	path_t *head;
	path_t *curr, *next;
	char **paths, *path, *path_str, *PATH;
	int i;
	size_t len;

	PATH = getenv("PATH");
	paths = str_tok(PATH, ":");
	if (!paths)
	{
		printf("Could not tokenize path\n");
		exit(98);
	}
	head = malloc(sizeof(path_t));
	if (!head)
		return (NULL);

	head->next = NULL;
	head->path = malloc_str(paths[0]);
	curr = head;

	for (i = 1; paths[i]; i++)
	{
		next = malloc(sizeof(path_t));
		if (!next)
			return (NULL);

		next->path = malloc_str(paths[i]);
		next->next = NULL;
		curr->next = next;
		curr = next;
	}

	free(paths);
	return (head);
}

/**
 * free_path_list - frees the memory allocated to a path list
 * @head: pointer to the list head
 *
 * Return: void
 */
void free_path_list(path_t *head)
{
	path_t *tmp;

	if (!head)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp->path);
		free(tmp);
	}
}
