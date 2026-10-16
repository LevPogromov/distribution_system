#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define G 6.67430e-11

struct Particle {
    double m;
    double x;
    double y;
    double vx;
    double vy;
};

int main(int argc, char* argv[]) {
    if (argc < 3 || argc > 4) {
        fprintf(stderr, "Please retry this: %s <t_end>  <input file> [-output]\n", argv[0]);
        return 1;
    }
    int write_output = 0;
    if (argc == 4) {
        if (strcmp(argv[3], "-output") == 0) {
            write_output = 1;
        }

    }

    int t_end = strtol(argv[1], NULL, 10);
    char* file_name = argv[2];
    FILE* file = fopen(file_name, "r");
    FILE* out = NULL;
    int num_particles;
    fscanf(file, "%d", &num_particles);

    struct Particle* particles = malloc(num_particles * sizeof(struct Particle));
    for (int i = 0; i < num_particles; i++) {
        double z, vz;
        fscanf(file, "%lf %lf %lf %lf %lf %lf %lf", &particles[i].m, &particles[i].x, 
        &particles[i].y, &z, &particles[i].vx, &particles[i].vy, &vz);
    }
    fclose(file);

    double* force_x = calloc(num_particles, sizeof(double));
    double* force_y = calloc(num_particles, sizeof(double));
    if (write_output) {
        out = fopen("output_basic.csv", "w");
        fprintf(out, "0");
        for (int i = 0; i < num_particles; i++) {
            fprintf(out, ", %lf, %lf", particles[i].x, particles[i].y);
        }
        fprintf(out, "\n");
    }
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int t = 1; t <= t_end; t++) {
        for (int i = 0; i < num_particles; i++) {
            force_x[i] = 0;
            force_y[i] = 0;
        }
        for (int i = 0; i < num_particles - 1; i++) {
            for (int j = i + 1; j < num_particles; j++) {
                double x = particles[j].x - particles[i].x;
                double y = particles[j].y - particles[i].y;
                double r2 = x * x + y * y;
                double r3 = r2 * sqrt(r2);
                double fx = G * particles[i].m * particles[j].m * x / r3;
                double fy = G * particles[i].m * particles[j].m * y / r3;
                force_x[i] += fx;
                force_y[i] += fy;
                force_x[j] -= fx;
                force_y[j] -= fy;
            }
        }
        for (int i = 0; i < num_particles; i++) {
            particles[i].x += particles[i].vx;
            particles[i].y += particles[i].vy;

            particles[i].vx += force_x[i] / particles[i].m;
            particles[i].vy += force_y[i] / particles[i].m;
        }
        if (write_output) {
            fprintf(out, "%d", t);
            for (int i = 0; i < num_particles; i++) {
                fprintf(out, ", %lf, %lf", particles[i].x, particles[i].y);
            }
            fprintf(out, "\n");
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    double spent = end.tv_sec - start.tv_sec + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Time spent: %lf\n", spent);
    if (write_output) {
        fclose(out);
    }
    free(particles);
    free(force_x);
    free(force_y);
    return 0;
}