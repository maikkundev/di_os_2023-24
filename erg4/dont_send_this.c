// #include <stdio.h>
// #include <stdlib.h>
// #include <sys/wait.h>
// #include <unistd.h>

// int main() {
//   FILE *file = fopen("output.txt", "a");

//   while (1) {
//     for (int i = 0; i < 3; i++) {
//       pid_t pid = fork();
//       if (pid == 0) {
//         // Child process 1
//         if (i == 0) {
//           printf("ThisIsASeriesOfSymbols!%d\n", getpid());
//           fprintf(file, "ThisIsASeriesOfSymbols!%d\n", getpid());
//           exit(0);
//         }
//         // Child process 2
//         if (i == 1) {
//           printf("ThisIsASeriesOfSymbols!!%d\n", getpid());
//           fprintf(file, "ThisIsASeriesOfSymbols!!%d\n", getpid());
//           exit(0);
//         }
//         // Child process 3
//         if (i == 2) {
//           printf("ThisIsASeriesOfSymbols%d\n", getpid());
//           fprintf(file, "ThisIsASeriesOfSymbols%d\n", getpid());
//           exit(0);
//         }
//         exit(0);
//       } else if (pid > 0) {
//         // Parent process
//         wait(NULL); // Wait for child process to finish
//       } else {
//         // Fork failed
//         printf("Fork failed (500)\n");
//         exit(500);
//       }
//     }
//   }
//   exit(0);
// }