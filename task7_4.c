#include <stdio.h>
#include <stdlib.h>

void display_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    char line[1024];
    int line_count = 0;

    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    printf("--- File: %s ---\n", filename);

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
        line_count++;

        if (line_count == 20) {
            printf("\n-- Press Enter to continue --");
            getchar(); 
            line_count = 0;
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> [file2] ...\n", argv[0]);
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        display_file(argv[i]);
    }

    return EXIT_SUCCESS;
}
