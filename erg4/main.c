#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>

int main() {
    FILE *file = fopen("output.txt", "a");

    // Create semaphores
    sem_t *sem1 = sem_open("/sem1", O_CREAT, 0644, 1);
    sem_t *sem2 = sem_open("/sem2", O_CREAT, 0644, 0);
    sem_t *sem3 = sem_open("/sem3", O_CREAT, 0644, 0);

    while (1) {
        for (int i = 0; i < 3; i++) {
            pid_t pid = fork();
            if (pid == 0) {
                // Child process
                if (i == 0) {
                    sem_wait(sem1);
                    printf("ThisIsASeriesOfSymbols!%d\n", getpid());
                    fprintf(file, "ThisIsASeriesOfSymbols!%d\n", getpid());
                    sem_post(sem2);
                } else if (i == 1) {
                    sem_wait(sem2);
                    printf("ThisIsASeriesOfSymbols!!%d\n", getpid());
                    fprintf(file, "ThisIsASeriesOfSymbols!!%d\n", getpid());
                    sem_post(sem3);
                } else if (i == 2) {
                    sem_wait(sem3);
                    printf("ThisIsASeriesOfSymbols%d\n", getpid());
                    fprintf(file, "ThisIsASeriesOfSymbols%d\n", getpid());
                    sem_post(sem1);
                }
                exit(0);
            } else if (pid > 0) {
                // Parent process
                wait(NULL); // Wait for child process to finish
            } else {
                // Fork failed
                printf("Fork failed (500)\n");
                exit(500);
            }
        }
    }

    // Close and unlink semaphores
    sem_close(sem1);
    sem_close(sem2);
    sem_close(sem3);
    sem_unlink("/sem1");
    sem_unlink("/sem2");
    sem_unlink("/sem3");

    exit(0);
}
