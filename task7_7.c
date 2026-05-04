#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

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
        if (strstr(entry->d_name, ".c") != NULL) {
            if (stat(entry->d_name, &st) == -1) continue;

            printf("Знайдено файл: %s. Надати іншим дозвіл на читання? (y/n): ", entry->d_name);
            scanf("%s", answer);

            if (strcmp(answer, "y") == 0 || strcmp(answer, "Y") == 0) {
                if (chmod(entry->d_name, st.st_mode | S_IROTH | S_IRGRP) == 0) {
                    printf("Дозвіл надано.\n");
                } else {
                    perror("Помилка chmod");
                }
            }
        }
    }

    closedir(dir);
    return EXIT_SUCCESS;
}
