#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "timer.h"

int main(int argc, char* argv[]) {
    if (argc > 3) {
        printf("Using: ./task1_openmp <attempts> <thread_count>\n");
        return 1;
    }
    long attempts = strtol(argv[1], NULL, 10);
    long thread_count = strtol(argv[2], NULL, 10);
    long dots = 0;
    double start, finish;
    
    GET_TIME(start);

#pragma omp parallel num_threads(thread_count) reduction(+: dots) 
{
    unsigned int seed = (unsigned int)(time(NULL) ^ (omp_get_thread_num() * 2654435761u));

    #pragma omp for
    for (long i = 0; i < attempts; i++) {
        double x = (double)rand_r(&seed)/RAND_MAX*2.0-1.0; //float in range -1 to 1
        double y = (double)rand_r(&seed)/RAND_MAX*2.0-1.0; //float in range -1 to 1
        
        if (x * x + y * y <= 1.0) {
            dots++;
        }
    }
}

    GET_TIME(finish);
    
    printf("Elapsed time = %e seconds\n", finish - start);
    double pi = (double)dots / (double)attempts;
    printf("Pi = %.9f", 4*pi);
    return 0;
}