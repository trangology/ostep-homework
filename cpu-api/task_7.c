#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        // Fork failed
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        // Child process
        close(STDOUT_FILENO); // Close standard output
        printf("This message won't be printed to stdout\n");
        exit(EXIT_SUCCESS);
    }
    else
    {
        // Parent process
        wait(NULL); // Wait for the child to finish
        printf("Child process completed.\n");
    }

    return 0;
}

//  Answer: The message at line 19 won't be printed out to the closed file descriptor.
