#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define G 6.67430e-11

struct Particle {
    double m;
    double x;
    double y;
    double vx;
    double vy;
};
struct Particle* particles;

int thread_count = 0, t_end = 0, num_particles = 0, counter = 0, t = 0;

pthread_cond_t cond;
pthread_mutex_t mutex;

double* local_force_x;
double* local_force_y;
double* force_x;
double* force_y;
FILE* out;

void barier() {
    pthread_mutex_lock(&mutex);
    counter++;
    if (counter == thread_count) {
        counter = 0;
        pthread_cond_broadcast(&cond);
    } else {
        while (pthread_cond_wait(&cond, &mutex) != 0);
    }
    pthread_mutex_unlock(&mutex);
}

void* routine(void* rank) {
    int my_rank = (int)rank;
    int particle_start = my_rank * (num_particles - 1) / thread_count;
    int particle_end = (my_rank + 1) * (num_particles - 1) / thread_count;
    while (t != t_end) {

        for (int i = 0; i < num_particles; i++) {
            local_force_x[my_rank * num_particles + i] = 0;
            local_force_y[my_rank * num_particles + i] = 0;
        }

        for (int i = particle_start; i < particle_end; i++) {
            for (int j = i + 1; j < num_particles; j++) {

                double x = particles[j].x - particles[i].x;
                double y = particles[j].y - particles[i].y;

                double r2 = x * x + y * y;
                double r3 = r2 * sqrt(r2);

                double fx =
                    G * particles[i].m * particles[j].m * x / r3;

                double fy =
                    G * particles[i].m * particles[j].m * y / r3;

                local_force_x[my_rank * num_particles + i] += fx;
                local_force_y[my_rank * num_particles + i] += fy;

                local_force_x[my_rank * num_particles + j] -= fx;
                local_force_y[my_rank * num_particles + j] -= fy;
            }
        }

        barier();

        int force_start = my_rank * num_particles / thread_count;

        int force_end = (my_rank + 1) * num_particles / thread_count;

        for (int i = force_start; i < force_end; i++) {
            force_x[i] = 0;
            force_y[i] = 0;

            for (int j = 0; j < thread_count; j++) {
                force_x[i] += local_force_x[j * num_particles + i];
                force_y[i] += local_force_y[j * num_particles + i];
            }
        }

        barier();

        for (int i = force_start; i < force_end; i++) {
            particles[i].x += particles[i].vx;
            particles[i].y += particles[i].vy;

            particles[i].vx += force_x[i] / particles[i].m;
            particles[i].vy += force_y[i] / particles[i].m;
        }

        barier();

        if (my_rank == 0) {
            t++;
            fprintf(out, "%d", t);
            for (int i = 0; i < num_particles; i++) {
                fprintf(out, ", %lf, %lf", particles[i].x, particles[i].y);
            }
            fprintf(out, "\n");
        }

        barier();
    }

    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Please retry this: %s <number of threads>  <t_end>  <input file>\n", argv[0]);
        return 1;
    }
    thread_count = strtol(argv[1], NULL, 10);
    t_end = strtol(argv[2], NULL, 10);
    char* file_name = argv[3];
    FILE* file = fopen(file_name, "r");
    fscanf(file, "%d", &num_particles);
    particles = malloc(num_particles * sizeof(struct Particle));
    pthread_t* thread_handles = malloc(thread_count * sizeof(pthread_t));
    pthread_cond_init(&cond, NULL);
    pthread_mutex_init(&mutex, NULL);
    local_force_x = calloc(thread_count * num_particles, sizeof(double));
    local_force_y = calloc(thread_count * num_particles, sizeof(double));
    force_x = calloc(num_particles, sizeof(double));
    force_y = calloc(num_particles, sizeof(double));

    for (int i = 0; i < num_particles; i++) {
        double z, vz;
        fscanf(file, "%lf %lf %lf %lf %lf %lf %lf", &particles[i].m, &particles[i].x,
        &particles[i].y, &z, &particles[i].vx, &particles[i].vy, &vz);        
    }
    fclose(file);
    out = fopen("output.csv", "w");
    fprintf(out, "0");
    for (int i = 0; i < num_particles; i++) {
       fprintf(out, ", %lf, %lf", particles[i].x, particles[i].y);
    }
    fprintf(out, "\n");
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < thread_count; i++) {
        pthread_create(&thread_handles[i], NULL, routine, (void*)i);
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(thread_handles[i], NULL);
    }
    pthread_cond_destroy(&cond);
    pthread_mutex_destroy(&mutex);
    clock_gettime(CLOCK_MONOTONIC, &end);
    double spent = end.tv_sec - start.tv_sec + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Time spent: %lf\n", spent);
    fclose(out);
    free(particles);
    free(thread_handles);
    free(local_force_x);
    free(local_force_y);
    free(force_x);
    free(force_y);
}