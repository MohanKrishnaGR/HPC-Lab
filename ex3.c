#include <stdio.h>
#include <omp.h>
#include <time.h>

#define N 100000000  // Large loop size

void sequential_loop() {
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += i;
    }
    printf("Sum (Sequential): %lld\n", sum);
}

void parallel_loop() {
    long long sum = 0;
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < N; i++) {
        sum += i;
    }
    printf("Sum (Parallel): %lld\n", sum);
}

int main() {
    clock_t start, end;
    double cpu_time_used;

    // Sequential execution
    start = clock();
    sequential_loop();
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time (Sequential): %f seconds\n", cpu_time_used);

    // Parallel execution
    start = clock();
    parallel_loop();
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time (Parallel): %f seconds\n", cpu_time_used);

    return 0;
}
