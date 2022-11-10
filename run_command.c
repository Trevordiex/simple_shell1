#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include "main.h"

/**
* run_command - execs a command and returns
* @exec_name: the string passed as argv[0]
*
* Return: 1 if execution is successful and 0 if successful with EOF else -1
*/
int run_command(const char *exec_name, const char *line)
{
    pid_t child_pid;
    char *vargs[] = {NULL, NULL};
    int status;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("fork");
    }
    if (child_pid == 0)
    {
        vargs[0] = (char *) line;
        if (execve(line, vargs, NULL) == -1)
        {
            perror(exec_name);
        }
        exit(0);
    }
    else
    {
        wait(&status);
    }
    
    return (1);
}