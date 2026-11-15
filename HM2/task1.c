#include <stdio.h>
#include <stdlib.h>
#include "timer.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Using: ./task1_single <attempts>\n");
        return 1;
    }
    long attempts = strtol(argv[1], NULL, 10);
    long dots = 0;
    double x, y;
    double start, finish;
    GET_TIME(start);
    for (long i = 0; i < attempts; i++) {
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
