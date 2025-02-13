// Parallel Matrix Multiplication Using OpenMP
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 500  // Matrix size (adjustable)

int main() {
    int A[N][N], B[N][N], C[N][N] = {0};

    // Initialize matrices
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
        }
    }

    double start_time = omp_get_wtime();
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    double end_time = omp_get_wtime();

    printf("Parallel Matrix Multiplication Completed. Time Taken: %f seconds\n", end_time - start_time);
    return 0;
}
