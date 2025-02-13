// 1. Parallel Array Addition Using OpenMP
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define N 1000000  // Large array size

int main() {
    int *A, *B, *C;
    A = (int*)malloc(N * sizeof(int));
    B = (int*)malloc(N * sizeof(int));
    C = (int*)malloc(N * sizeof(int));

    // Initialize arrays
    for (int i = 0; i < N; i++) {
        A[i] = rand() % 100;
        B[i] = rand() % 100;
    }

    double start_time = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        C[i] = A[i] + B[i];
    }
    double end_time = omp_get_wtime();

    printf("Parallel Array Addition Completed. Time Taken: %f seconds\n", end_time - start_time);

    free(A); free(B); free(C);
    return 0;
}
