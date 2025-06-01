#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork(); // creates a new process
    if (pid == 0)
        printf("Child Process: %d\n", getpid());
    else
        printf("Parent Process: %d\n", getpid());
    return 0;
}
