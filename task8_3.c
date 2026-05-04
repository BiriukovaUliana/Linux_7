#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int is_sorted(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) return 0;
    }
    return 1;
}

void run_test(const char *test_name, int *arr, int n) {
    clock_t start = clock();
    qsort(arr, n, sizeof(int), compare);
    clock_t end = clock();
    
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("--- %s ---\n", test_name);
    printf("Time: %f s\n", time_spent);
    
    if (is_sorted(arr, n)) {
        printf("Status: OK\n\n");
    } else {
        printf("Status: ERROR\n\n");
    }
}

void fill_random(int *arr, int n) { for(int i=0; i<n; i++) arr[i] = rand() % n; }
void fill_sorted(int *arr, int n) { for(int i=0; i<n; i++) arr[i] = i; }
void fill_reverse(int *arr, int n) { for(int i=0; i<n; i++) arr[i] = n - i; }
void fill_identical(int *arr, int n) { for(int i=0; i<n; i++) arr[i] = 7; }

int main() {
    srand(time(NULL));
    int n = 100000;
    int *arr = malloc(n * sizeof(int));

    printf("QSORT RESEARCH (n = %d)\n\n", n);

    fill_random(arr, n);
    run_test("Random", arr, n);

    fill_sorted(arr, n);
    run_test("Sorted", arr, n);

    fill_reverse(arr, n);
    run_test("Reverse", arr, n);

    fill_identical(arr, n);
    run_test("Identical", arr, n);

    free(arr);
    return 0;
}
