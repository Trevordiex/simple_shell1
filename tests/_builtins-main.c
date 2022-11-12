#include <stdlib.h>
#include "main.h"

int main(int argc, char **argv)
{
    void (*cmd)(void);
    if (argc != 2)
    {
        printf("Usage: %s builtin\n", argv[0]);
        exit(1);
    }

    cmd = get_builtin(argv[1]);
    if (!cmd)
    {
        printf("builtin %s: does not exist\n", argv[1]);
        exit(1);
    }
    (*cmd)();

    exit(0);
}