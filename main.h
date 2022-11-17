#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <unistd.h>
#include <stdio.h>

/**
 * struct path - a struct item for linked list of paths
 * @path: the node path as a string
 * @next: pointer to next list node
 *
 * Description: this is used for iterating all the paths in the sys
 */
typedef struct path
{
	char *path;
	struct path *next;
} path_t;

/**
 * struct env - a struct attaching each shell builtin to a callable name
 * @name: the callable name of the builtin
 * @cmd: a pointer to the builtin function
 *
 * Description: gives every builtin function a name for search purposes
 */
typedef struct env
{
	char *name;
	void (* cmd)(char **);
} env_builtin;

typedef void (*cmd)(char **);

int run_command(const char *, const char *, char **);
char **str_tok(char *, char *);
int _setenv(const char *name, const char *value, int overwrite);
path_t *build_path_list(void);
void free_path_list(path_t *);
char *_which(char *);
int print(char *string, char *sub);
void itos(int n);

/* builtins.h */
cmd get_builtin(char *);


/* string.h */
int _strcmp(char *s1, char *s2);
int is_equal(char *s1, char *s2);
char *malloc_str(char *);
char *_memcpy(char *dest, char *src, unsigned int n);
size_t _strlen(char *str);

#endif
