#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void list_files_recursive(const char *path) {
    DIR *dir = opendir(path);
    struct dirent *entry;
    struct stat file_stat;
    char full_path[1024];

    if (dir == NULL) {
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        if (stat(full_path, &file_stat) == -1) {
            continue;
        }

        printf("%s\n", full_path);

        if (S_ISDIR(file_stat.st_mode)) {
            list_files_recursive(full_path);
        }
    }

    closedir(dir);
}

int main() {
    list_files_recursive(".");
    return EXIT_SUCCESS;
}
