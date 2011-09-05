#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    char **new_args;

    new_args = (char **)malloc(sizeof(char *) * (argc + 3));
    new_args[0] = "valgrind";
    asprintf(&(new_args[1]), "--log-file=/tmp/valwrap/%s", PROGRAM_TO_INVOKE);
    new_args[2] = PROGRAM_TO_INVOKE;
    memcpy(new_args + 3, argv + 1, sizeof(char *) * (argc - 1));
    new_args[argc + 2] = NULL;

    execvp("valgrind", new_args);
    return 1; 
}

