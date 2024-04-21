#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main()
{
    int file_descriptor;

    // Open a file named "example.txt" for writing with read and write permissions
    file_descriptor = open("example.txt", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);

    // Check if the file was opened successfully
    if (file_descriptor == -1) {
        perror("Unable to open file");
        exit(1); // Return an error code
    }

    char *child_data = "Hello, world!\n";
    char *parent_data = "Hello, world!\n";

    // File operations go here
    int rc = fork();

    if (rc < 0) {
        printf("Fork failed!\n");
    }
    else if (rc == 0) {
        if (write(file_descriptor, parent_data, strlen(parent_data)) == -1) {
            perror("Write to the parent failed!\n");
            exit(EXIT_FAILURE);
        }
        else {
            printf("Write to the parent succeed!\n");
        }
    }
    else {
        if (write(file_descriptor, child_data, strlen(child_data)) == -1) {
            perror("Write to the children failed!\n");
            exit(EXIT_FAILURE);
        }
        else {
            printf("Write to the children succeed!\n");
        }
    }
    
    // Close the file when done
    close(file_descriptor);

    return 0;
}


// Result:
// Both the child and parent processes can access to write data into the file descriptor.