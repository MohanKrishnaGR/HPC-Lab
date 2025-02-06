//Summing an Array in Parallel with Timing

#include <stdio.h>
#include <omp.h>

int main() {
    const int N = 1000000;
    int a[N];
    
    // Initialize the array with values
    for (int i = 0; i < N; i++) {
        a[i] = i;
    }
    
    // Use long long to avoid overflow
    long long global_sum = 0;
    double start_time = omp_get_wtime();
    
    #pragma omp parallel
    {
        long long local_sum = 0;
        
        // Distribute iterations among threads using static scheduling
        #pragma omp for schedule(static, 1000)
        for (int i = 0; i < N; i++) {
            local_sum += a[i];
        }
        
        // Combine local sums into the global sum using a critical section
        #pragma omp critical
        {
            global_sum += local_sum;
        }
    }
    
    double end_time = omp_get_wtime();
    
    // Calculate the expected sum as long long to avoid overflow
    long long expected = ((long long)N * (N - 1)) / 2;
    printf("Computed sum = %lld, Expected sum = %lld\n", global_sum, expected);
    printf("Time taken for parallel sum: %f seconds\n", end_time - start_time);
    
    return 0;
}
