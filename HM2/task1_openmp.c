#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "timer.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Using: ./task1_openmp <attempts> <thread_count>\n");
        return 1;
    }
    long attempts = strtol(argv[1], NULL, 10);
    long thread_count = strtol(argv[2], NULL, 10);
    int dots = 0;
    double x, y;
    double start, finish;
    
    GET_TIME(start);
    #pragma omp parallel for num_threads(thread_count) reduction(+: dots)
    for (int i = 0; i < attempts; i++) {
        x = (double)rand()/RAND_MAX*2.0-1.0; //float in range -1 to 1
        y = (double)rand()/RAND_MAX*2.0-1.0; //float in range -1 to 1

        if (x * x + y * y <= 1) {
            dots++;
        }
    }
    GET_TIME(finish);
    
    printf("Elapsed time = %e seconds\n", finish - start);
    double pi = (double)dots / (double)attempts;
    printf("Pi = %.9f", 4*pi);
    return 0;
}