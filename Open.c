#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    // Open or create a file with read/write permissions
    int fd = open("example.txt", O_RDWR | O_CREAT, 0644);
    
    if (fd == -1) {
        perror("open failed");
        return 1;
    }
    
    printf("File opened successfully, file descriptor: %d\n", fd);
    
    // Close the file
    close(fd);
    return 0;
}
