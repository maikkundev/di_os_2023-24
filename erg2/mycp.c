#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mycp.h"

void mycp(char *file1, char *file2, int bufferSize) {
    FILE *source, *destination;
    char *buffer;

    // Allocate buffer
    buffer = (char *)malloc(bufferSize);
    if (buffer == NULL) {
        perror("Error allocating buffer");
        exit(EXIT_FAILURE);
    }

    // Open the source file for reading
    source = fopen(file1, "rb");
    if (source == NULL) {
        perror("Error opening source file");
        free(buffer);
        exit(EXIT_FAILURE);
    }

    // Open the destination file for writing
    destination = fopen(file2, "wb");
    if (destination == NULL) {
        perror("Error opening destination file");
        fclose(source);
        free(buffer);
        exit(EXIT_FAILURE);
    }

    // Copy the contents of the source file to the destination file
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, bufferSize, source)) > 0) {
        fwrite(buffer, 1, bytesRead, destination);
    }

    // Close the files
    fclose(source);
    fclose(destination);

    // Free the buffer
    free(buffer);

    printf("File copied successfully.\n");
}