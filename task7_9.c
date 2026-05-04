#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    struct timespec start, end;
    long long elapsed_ms;

    clock_gettime(CLOCK_MONOTONIC, &start);

    for (int i = 0; i < 1000000; i++) {
        // Імітація роботи
    }
    usleep(500000); // Пауза 500 мс для тесту

    clock_gettime(CLOCK_MONOTONIC, &end);

    elapsed_ms = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;

    printf("Час виконання: %lld мс\n", elapsed_ms);

    return EXIT_SUCCESS;
}

