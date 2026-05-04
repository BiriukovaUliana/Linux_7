#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    double n;
    int count = 5;

    srand((unsigned int)time(NULL));

    printf("Enter n for range [0.0, n]: ");
    if (scanf("%lf", &n) != 1) {
        return EXIT_FAILURE;
    }

    printf("\n(a) Range [0.0, 1.0]:\n");
    for (int i = 0; i < count; i++) {
        double val = (double)rand() / RAND_MAX;
        printf("%f\n", val);
    }

    printf("\n(b) Range [0.0, %.2f]:\n", n);
    for (int i = 0; i < count; i++) {
        double val = ((double)rand() / RAND_MAX) * n;
        printf("%f\n", val);
    }

    return EXIT_SUCCESS;
}
