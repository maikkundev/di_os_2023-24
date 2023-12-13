#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s -n <input_file> (501)\n", argv[0]);
        // Exit with error code 501: Wrong number of arguments
        exit(501);
    }

    // Get file name
    char *file1 = argv[argc - 2];

    int fd[2];
    pipe(fd);

    pid_t pid = fork();

    if (pid == 0) { // Child process
        // Close unused read end
        close(fd[0]);

        // Redirect stdout to the pipe
        dup2(fd[1], STDOUT_FILENO);

        // Execute cat command
        execlp("cat", "cat", file1, NULL);
        perror("Execution failed - could not execute cat command (510)\n");

        // Exit with error code 510: Execution failed - could not execute cat command (510)
        exit(510);
    } else if (pid > 0) { // Parent process
        // Close unused write end
        close(fd[1]);

        // Declare a buffer to store each line read from the pipe
        char line[256];

        // Convert the read end of the pipe to a FILE stream for easier line-by-line reading
        FILE *stream = fdopen(fd[0], "r");

        // Read lines from the pipe until there are no more lines
        while (fgets(line, sizeof(line), stream) != NULL) {
            // Print each line with a prefix indicating it was received through the pipe
            printf("Data received through pipe: %s\n", line);
        }

        // Close the FILE stream
        fclose(stream);

        // Wait for the child process to finish before the parent process exits
        // This prevents the child process from becoming a zombie process
        wait(NULL);
    } else {
        // Print an error message indicating that the fork call failed
        perror("Fork failed (511)\n");

        // Exit with error code 511: Fork failed
        exit(511);
}

    // Successful exit
    exit(100);
}