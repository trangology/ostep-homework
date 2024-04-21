#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int rc = fork();

    if (rc < 0)
    {
        printf("Fork failed!");
        exit(1);
    }
    else if (rc == 0)
    {
        wait(NULL);
        printf("Executing the ls command...\n");
        execl("/bin/ls", "ls", NULL);
    }
    else
    {
        printf("Done!\n");
    }

    return 0;
}

// Answer:
// If we use `wait()` in the child, the parent will be executed first.