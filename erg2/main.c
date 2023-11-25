#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "mycp.h"

// Default buffer size
#define DEFAULT_BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    clock_t start;

    // Start a clock to measure the time taken
    start = clock();
    if (argc < 3 || argc > 4) {
        fprintf(stderr, "Usage: %s [-bBufferSize] <sourceFile> <destinationFile> (501)\n", argv[0]);
        // Exit with error code 501: Wrong number of arguments
        exit(501);
    }

    // Process optional buffer size
    int bufferSize = DEFAULT_BUFFER_SIZE;

    // Check if the first argument is "-b"
    if (argc == 4 && strncmp(argv[1], "-b", 2) == 0) {
        bufferSize = atoi(argv[1] + 2); // Skip the "-b" prefix
        if (bufferSize <= 0) {
            fprintf(stderr, "Invalid buffer size (502)\n");
            // Exit with error code 502: Invalid buffer size
            exit(502);
        }
    }

    // Get file names
    char *file1 = argv[argc - 2];
    char *file2 = argv[argc - 1];

    // Call the mycp function
    mycp(file1, file2, bufferSize);

    printf("Time taken: %f\n", ((double) clock() - (double) start) / CLOCKS_PER_SEC);
    return 0;
}