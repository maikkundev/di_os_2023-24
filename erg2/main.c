#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "mycp.h"

int main(int argc, char *argv[]) {
    clock_t start;

    start = clock();
    if (argc < 3 || argc > 4) {
        fprintf(stderr, "Usage: %s [-b<BufferSize>] <file1> <file2>\n", argv[0]);
        exit(1);
    }

    // Process optional buffer size
    int bufferSize = 4096; // Default buffer size

    if (argc == 4 && strncmp(argv[1], "-b", 2) == 0) {
        bufferSize = atoi(argv[1] + 2); // Skip the "-b" prefix
        if (bufferSize <= 0) {
            fprintf(stderr, "Invalid buffer size\n");
            exit(1);
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