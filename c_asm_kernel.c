#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern mp2_c(int *vector, int size);
extern mp2_asm(int *vector, int size);

double time_kernel(void (*kernel)(int*, int), int *vector, int size) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    kernel(vector, size);
    clock_gettime(CLOCK_MONOTONIC, &end);
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
}

int main(){
	int i, j;
	 int sizes[] = {2^20, 2^24, 2^30}; 
    int num_trials = 30;

    for (i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++) {
        int size = sizes[i];
        int *vector = (int*)malloc(size * sizeof(int));


        double c_time = 0.0, assembly_time = 0.0;
        for (j = 0; j < num_trials; j++) {
            c_time += time_kernel(mp2_c, vector, size);
            assembly_time += time_kernel(mp2_asm, vector, size);
        }

        c_time /= num_trials;
        assembly_time /= num_trials;

        printf("Vector size: %d\nC kernel time: %.6f s\nAssembly kernel time: %.6f s\n", size, c_time, assembly_time);

        free(vector);
    }

	return 0;
}
