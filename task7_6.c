#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int filter_dirs(const struct dirent *entry) {
    struct stat st;
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
        return 0;
    }
    
    if (stat(entry->d_name, &st) == 0) {
        return S_ISDIR(st.st_mode);
    }
    return 0;
}

int main() {
    struct dirent **namelist;
    int n;

    n = scandir(".", &namelist, filter_dirs, alphasort);
    if (n < 0) {
        perror("scandir");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", namelist[i]->d_name);
        free(namelist[i]);
    }
    free(namelist);

    return EXIT_SUCCESS;
}
