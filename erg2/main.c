#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
    char buf;
    int fd1, fd2;

    if (argc != 3) {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    if ((fd1 = open(argv[1], O_RDONLY)) == -1) {
        perror(argv[1]);
        return 2;
    }

    if ((fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1) {
        perror(argv[2]);
        return 3;
    }

    while (read(fd1, &buf, 1) > 0) {
        write(fd2, &buf, 1);
    }

    close(fd1);
    close(fd2);


    return 0;
}