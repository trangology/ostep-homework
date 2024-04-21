#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int rc = fork();
    int status;

    if (rc < 0)
    {
        printf("Fork failed!");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("Starting the child process...\n");
    }
    else
    {
        waitpid(rc, &status, 0);
        printf("Done!\n");
    }

    return 0;
}

// Answer: waitpid() would be useful for
// 1. obtaining the exit status of the child process
// 2. handling multiple child processes