#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    // Open a file
    int fd = open("example.txt", O_RDWR);
    
    if (fd == -1) {
        perror("open failed");
        return 1;
    }
    
    // Close the file
    if (close(fd) == -1) {
        perror("close failed");
        return 1;
    }
    
    printf("File closed successfully\n");
    return 0;
}#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    // Open a file
    int fd = open("example.txt", O_RDWR);
    
    if (fd == -1) {
        perror("open failed");
        return 1;
    }
    
    // Close the file
    if (close(fd) == -1) {
        perror("close failed");
        return 1;
    }
    
    printf("File closed successfully\n");
    return 0;
}
