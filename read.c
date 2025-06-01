#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    char buffer[100];
    
    // Open a file for reading
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("open failed");
        return 1;
    }
    
    // Read up to 99 bytes from the file
    ssize_t bytes_read = read(fd, buffer, 99);
    if (bytes_read == -1) {
        perror("read failed");
        close(fd);
        return 1;
    }
    
    // Null-terminate the buffer for printing
    buffer[bytes_read] = '\0';
    printf("Read %zd bytes: %s\n", bytes_read, buffer);
    
    close(fd);
    return 0;
}
