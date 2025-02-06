//  Adding Two Arrays in Parallel with Timing

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000000

int main(void) {
    // Allocate arrays dynamically to avoid stack overflow
    float *a = (float *)malloc(N * sizeof(float));
    float *b = (float *)malloc(N * sizeof(float));
    float *c = (float *)malloc(N * sizeof(float));

    // Check if memory allocation was successful
    if (a == NULL || b == NULL || c == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    int i;
    // Initialize arrays a and b
    for (i = 0; i < N; i++) {
        a[i] = i * 2.0;
        b[i] = i * 3.0;
    }

    // Measure time before starting parallel addition
    double start_time = omp_get_wtime();

    // Compute c = a + b in parallel
    #pragma omp parallel shared(a, b, c) private(i)
    {
        #pragma omp for
        for (i = 0; i < N; i++) {
            c[i] = a[i] + b[i];
        }
    }

    // Measure time after computation
    double end_time = omp_get_wtime();
    printf("Time taken for parallel array addition: %f seconds\n", end_time - start_time);

    // Print one element to verify the result (e.g., element at index 10)
    printf("c[10] = %f\n", c[10]);

    // Free dynamically allocated memory
    free(a);
    free(b);
    free(c);

    return 0;
}
