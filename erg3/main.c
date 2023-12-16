#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    FILE *file;
    int fd[2];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <inputFile> (501)\n", argv[0]);
        
        // Exit with error code 501: Wrong number of arguments
        exit(501);
    }

    // Open given file for reading
    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file (502)");

        // Exit with error code 502: File open error
        exit(502);
    }

    // Create pipe
    if (pipe(fd) == -1) {
        perror("Pipe creation failed (503)");

        // Exit with error code 503: Pipe creation failed
        exit(503);
    }

    // Create child in order to run sort
    pid_t child_pid = fork();
    if (child_pid == -1) {
        perror("Fork failed (505)");

        // Exit with error code 505: Fork failed
        exit(505);
    }
    // Child code
    if (child_pid == 0) {
        // Close pipe's output
        close(fd[1]);

        // Connect sort's input to the other end of the pipe
        dup2(fd[0], STDIN_FILENO);

        // Close the other end of the pipe
        close(fd[0]);

        // Execute sort
        execlp("/bin/sh", "sh", "-c", "sort -n | awk '{print \"Data received through pipe \" $0}'", (char *) NULL);

        // In case execution of sort fails
        perror("Execution failed (510)");

        // Exit with error code 510: Execution failed
        exit(510);
    }
    // Parent code
    else {
        // Close the read end of the pipe in the parent process
        close(fd[0]);

        char buffer[BUFFER_SIZE];
        ssize_t bytesRead;

        // Read the content of the file and write it to the pipe
        while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
            ssize_t written = write(fd[1], buffer, bytesRead);
            if (written == -1) {
                perror("Error writing to pipe (511)");
                // Exit with error code 511: Error writing to pipe
                exit(511);
            }
        }

        // Close the output end of the pipe
        close(fd[1]);

        // Wait for the child to complete
        wait(NULL);
    }

    // Close file
    fclose(file);

    return 0;
}