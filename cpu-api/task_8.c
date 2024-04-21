#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    int x = 10;

    // Create the pipe
    if (pipe(fd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    int pid1, pid2, status;
    char buffer[256];

    pid1 = fork();

    if (pid1 < 0) {
        printf("Fork pid1 failed!\n");
    }
    else if (pid1 == 0)
    {
        close(fd[0]);
        printf("Writing from pid1...\n");
        write(fd[1], "Hi, this is pid1!", 27);
        close(fd[1]);
    }
    else
    {
        waitpid(pid1, &status, 0);
        printf("done writing from pid1!\n");
        fflush(stdout);

        pid2 = fork();

        if (pid2 < 0)
        {
            printf("Fork pid2 failed!\n");
        }
        else if (pid2 == 0)
        {
            close(fd[1]);
            printf("reading from pid1...\n");
            read(fd[0], buffer, sizeof(buffer));
            printf("msg from pid1: %s\n", buffer);
            close(fd[0]);
        }
        else
        {
            waitpid(pid2, &status, 0);
            printf("done reading from pid1...\n");
            fflush(stdout);
        }
    }
}