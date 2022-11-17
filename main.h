#ifndef MAIN_H
#define MAIN_H
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <dirent.h>
#include <limits.h>
#include <string.h>

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
	void (* cmd)(void);
} env_builtin;

typedef void (*cmd)(void);

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

extern char **environ;

char *show_input(void);
void prompt(void);
char *_strcat(char *src);
int _strlen(char *str);
void place(char *str);
char *findfile(char *command);
char *find_command(char *command);
int compare(char *s1, char *s2);
int _strcmpdir(char *s1, char *s2);
int charput(char c);
void place(char *str);
char *str_concat(char *s1, char *s2);
int lookforslash(char *cmd);
int compareExit(char *s1, char *s2);
int compareEnv(char *s1, char *s2);
void execute_proc(char **cmd);
char **identify_string(char *parameter);
void controlC(int sig);

#endif
