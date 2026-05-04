#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

int main() {
    DIR *dir;
    struct dirent *entry;
    struct stat st;
    char answer[10];

    dir = opendir(".");
    if (dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (stat(entry->d_name, &st) == -1) continue;

        if (S_ISREG(st.st_mode)) {
            if (strcmp(entry->d_name, "task7_8.c") == 0 || strcmp(entry->d_name, "task7_8") == 0) {
                continue;
            }

            printf("Видалити файл '%s'? (y/n): ", entry->d_name);
            scanf("%s", answer);

            if (strcmp(answer, "y") == 0 || strcmp(answer, "Y") == 0) {
                if (unlink(entry->d_name) == 0) {
                    printf("Файл видалено.\n");
                } else {
                    perror("Помилка при видаленні");
                }
            }
        }
    }

    closedir(dir);
    return EXIT_SUCCESS;
}
