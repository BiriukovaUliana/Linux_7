#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp_in, *fp_out;
    char buffer[1024];

    fp_in = popen("rwho", "r");
    if (fp_in == NULL) {
        perror("Error executing rwho");
        return EXIT_FAILURE;
    }

    fp_out = popen("more", "w");
    if (fp_out == NULL) {
        perror("Error executing more");
        pclose(fp_in);
        return EXIT_FAILURE;
    }

    while (fgets(buffer, sizeof(buffer), fp_in) != NULL) {
        fputs(buffer, fp_out);
    }

    pclose(fp_in);
    pclose(fp_out);

    return EXIT_SUCCESS;
}
