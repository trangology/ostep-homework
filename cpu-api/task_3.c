#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int rc = fork();
    int status;

    if (rc < 0) {
        printf("Fork failed!");
        exit(1);
    }
    // child process
    else if (rc == 0) {
        printf("Hello\n");
    }
    // parent process
    else {
        // always waits for the child process to complete
        while (waitpid(rc, &status, 0)) {
            sleep(1);
        };
        printf("Goodbye\n");
    }

    return 0;
}
