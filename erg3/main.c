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
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open given file for reading
    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Create pipe
    if (pipe(fd) == -1) {
        perror("Pipe creation failed");
        exit(EXIT_FAILURE);
    }

    // Create child in order to run sort
    pid_t child_pid = fork();
    if (child_pid == -1) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) { // Child code
        // Close pipe's output
        close(fd[1]);

        // Connect sort's input to the other end of the pipe
        dup2(fd[0], STDIN_FILENO);

        // Close the other end of the pipe
        close(fd[0]);

        // Execute sort
        execlp("/bin/sh", "sh", "-c", "sort -n | awk '{print \"Data received through pipe \" $0}'", (char *) NULL);

        // In case execution of sort fails
        perror("Exec failed");
        exit(EXIT_FAILURE);
    }
    else { // Parent code
        // Close the read end of the pipe in the parent process
        close(fd[0]);

        char buffer[BUFFER_SIZE];
        ssize_t bytesRead;

        // Read the content of the file and write it to the pipe
        while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
            ssize_t written = write(fd[1], buffer, bytesRead);
            if (written == -1) {
                perror("Error writing to pipe");
                exit(EXIT_FAILURE);
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