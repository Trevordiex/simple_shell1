#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
* main - A super simple shell
* @Description: runs a single string command
* 
* Return: exit status
*/
int main(int argc, char **argv)
{
    char *line = NULL;
    size_t n = 0;
    int end;
    ssize_t len;


    while ((len = getline(&line, &n, stdin)) != -1)
    {
        if (line[len - 1] == '\n')
        {
            line[len - 1] = '\0';
            len--;
        }

        if (run_command(argv[0], line))
            printf("#cisfun$ ");
    }
}