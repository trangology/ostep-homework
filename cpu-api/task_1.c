#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>


int main() {
    int x = 100;

    int rc = fork();

    if (rc < 0) {
        printf("Fork failed!");
        exit(1);
    }
    else if (rc == 0) {
        // child process adds 50 to x
        x += 50;
        printf("Adding 50 to x, new x is: %d \n", x); // x = 150
    } 
    else {
        // parent process subtracts 100 from x
        x -= 100;
        printf("Subtracting 100 from x, new x is: %d \n", x); // x = 0
    }

    return 0;
}

// Explanation:
// Each process (child and parent) maintains its own copy of the variables. 
// Changes made to variables in one process do not affect variables in the other process.
