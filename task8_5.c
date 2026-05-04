#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    const char *filename = "test_file.txt";
    int fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        return 1;
    }

    write(fd, "Hello World", 11);

    off_t pos_before = lseek(fd, 0, SEEK_CUR);
    printf("Position before: %ld\n", pos_before);

    pwrite(fd, "Linux", 5, 6);

    off_t pos_after = lseek(fd, 0, SEEK_CUR);
    printf("Position after: %ld\n", pos_after);

    close(fd);
    return 0;
}
