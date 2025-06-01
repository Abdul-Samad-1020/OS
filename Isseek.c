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
    
    // Move offset to 7th byte from the start
    off_t offset = lseek(fd, 7, SEEK_SET);
    if (offset == -1) {
        perror("lseek failed");
        close(fd);
        return 1;
    }
    
    // Read from the new offset
    ssize_t bytes_read = read(fd, buffer, 99);
    if (bytes_read == -1) {
        perror("read failed");
        close(fd);
        return 1;
    }
    
    buffer[bytes_read] = '\0';
    printf("Read from offset %ld: %s\n", offset, buffer);
    
    close(fd);
    return 0;
}
