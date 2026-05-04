#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    const char *filename = "data.bin";
    unsigned char initial_data[] = {4, 5, 2, 2, 3, 3, 7, 9, 1, 5};
    unsigned char buffer[4];

    int fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Open error");
        return 1;
    }
    write(fd, initial_data, sizeof(initial_data));

    if (lseek(fd, 3, SEEK_SET) == -1) {
        perror("Lseek error");
        return 1;
    }

    ssize_t bytes_read = read(fd, buffer, 4);
    if (bytes_read == -1) {
        perror("Read error");
        return 1;
    }

    printf("Зчитано байтів: %zd\n", bytes_read);
    printf("Вміст буфера: ");
    for (int i = 0; i < bytes_read; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");

    close(fd);
    return 0;
}
