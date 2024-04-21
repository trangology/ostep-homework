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
        printf("Executing the ls command...\n");
        execl("/bin/ls", "ls", NULL);
    }
    else
    {
        printf("Done!\n");
    }

    return 0;
}

// Explanation:
// execl() was chosen in the example because it's simple 
// and suitable when we know the exact arguments at compile time.