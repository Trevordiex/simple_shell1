#include <stdlib.h>
#include "main.h"


int main(void)
{
    path_t *path, *tmp;
    
    path = build_path_list();
    tmp = path;
    while(tmp->next)
    {
        printf("%s\n", tmp->path);
        tmp = tmp->next;
    }
    free_path_list(path);
    return (0);
}