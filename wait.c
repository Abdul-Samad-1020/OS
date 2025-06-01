#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    
    if (pid == -1) {
        perror("fork failed");
        return 1;
    }
    
    if (pid == 0) {
        // Child process
        printf("Child (PID %d) is running\n", getpid());
        sleep(2); // Simulate work
        printf("Child is exiting\n");
        return 42; // Exit status
    } else {
        // Parent process
        int status;
        pid_t child_pid = wait(&status);
        if (child_pid == -1) {
            perror("wait failed");
            return 1;
        }
        
        if (WIFEXITED(status)) {
            printf("Child (PID %d) exited with status %d\n", child_pid, WEXITSTATUS(status));
        }
    }
    
    return 0;
}
