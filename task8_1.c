#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/resource.h>
#include <string.h>

int main() {
    const char *filename = "test_output.txt";
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Помилка відкриття файлу");
        return 1;
    }
    struct rlimit rl;
    rl.rlim_cur = 100; 
    rl.rlim_max = 1024;
    if (setrlimit(RLIMIT_FSIZE, &rl) == -1) {
        perror("Помилка setrlimit");
        return 1;
    }

    char buffer[200];
    memset(buffer, 'A', sizeof(buffer)); // Заповнюємо буфер символом 'A'
    size_t nbytes = 200;

    printf("Спроба записати: %zu байтів\n", nbytes);

    ssize_t count = write(fd, buffer, nbytes);

    if (count == -1) {
        perror("Помилка write");
    } else {
        printf("Фактично записано (count): %zd байтів\n", count);
        if (count < nbytes) {
            printf("Результат: count (%zd) != nbytes (%zu). Частковий запис успішно продемонстровано!\n", count, nbytes);
        }
    }

    close(fd);
    return 0;
}
