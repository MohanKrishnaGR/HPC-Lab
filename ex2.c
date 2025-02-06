#include <stdio.h>
#include <omp.h>
#include <time.h>

#define N 1000000

void without_thread() {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += i;
    }
    printf("Sum without thread: %d\n", sum);
}

void with_thread() {
    int sum = 0;
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < N; i++) {
        sum += i;
    }
    printf("Sum with thread: %d\n", sum);
}

int main() {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    without_thread();
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time without OpenMP: %f seconds\n", cpu_time_used);

    start = clock();
    with_thread();
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time with OpenMP: %f seconds\n", cpu_time_used);

    return 0;
}