#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>

#define SECONDS_IN_7_DAYS (7 * 24 * 60 * 60)

int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *entry;
    struct stat st;
    time_t now = time(NULL);
    char *path = (argc > 1) ? argv[1] : ".";

    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    printf("Файли у '%s', змінені за останні 7 днів:\n", path);
    printf("%-30s | %s\n", "Назва файлу", "Дата останньої зміни");
    printf("----------------------------------------------------------\n");

    while ((entry = readdir(dir)) != NULL) {
        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        if (stat(full_path, &st) == -1) continue;

        if (S_ISREG(st.st_mode)) {
            double diff = difftime(now, st.st_mtime);

            if (diff <= SECONDS_IN_7_DAYS) {
                printf("%-30s | %s", entry->d_name, ctime(&st.st_mtime));
            }
        }
    }

    closedir(dir);
    return EXIT_SUCCESS;
}
