#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "mycp.h"

void mycp(char *file1, char *file2, int bufferSize) {
    FILE *source, *destination;
    char *buffer;

    // Allocate buffer
    buffer = (char *)malloc(bufferSize);
    if (buffer == NULL) {
        perror("Error allocating buffer (505)");
        // Exit with error code 505: Error allocating buffer
        exit(505);
    }

    // Open the source file for reading
    source = fopen(file1, "rb");
    if (source == NULL) {
        perror("Error opening source file (510)");
        free(buffer);
        // Exit with error code 510: Error opening source file
        exit(510);
    }

    // Open the destination file for writing
    destination = fopen(file2, "wb");
    if (destination == NULL) {
        perror("Error opening destination file (511)");
        fclose(source);
        free(buffer);
        // Exit with error code 511: Error opening destination file
        exit(511);
    }

    // Copy the contents of the source file to the destination file
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, bufferSize, source)) > 0) {
        fwrite(buffer, 1, bytesRead, destination);
    }

    // Close the files
    fclose(source);
    fclose(destination);

    // Force write to disk
    sync();

    // Free the buffer
    free(buffer);

    printf("File copied successfully (%d).\n", bufferSize);
}