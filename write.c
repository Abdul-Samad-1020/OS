#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
    // Open or create a file for writing
    int fd = open("example.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open failed");
        return 1;
    }
    
    const char *data = "Hello, Operating Systems!\n";
    // Write data to the file
    ssize_t bytes_written = write(fd, data, strlen(data));
    if (bytes_written == -1) {
        perror("write failed");
        close(fd);
        return 1;
    }
    
    printf("Wrote %zd bytes to the file\n", bytes_written);
    
    close(fd);
    return 0;
}
