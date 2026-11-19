#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <chrono>
#include <omp.h>
int main(int argc, char* argv[]) {
    if (argc < 6) {
        std::cout << "Using: ./task3 <thread count> <size of grid> <block size> <c> <eps>\n";
        return 1;
    }
    int thread_count =strtol(argv[1], NULL, 10);
    int n = strtol(argv[2], NULL, 10);
    int block_size = strtol(argv[3], NULL, 10);
    double c = strtod(argv[4], nullptr);
    double eps = strtod(argv[5], nullptr);
    double h = 1.0 / (n-1);
    double h2 = h * h;
    std::vector<std::vector<double>>v(n, std::vector<double>(n,c));
    omp_set_num_threads(thread_count);
    double max_diff = __INT_MAX__;
    auto start = std::chrono::high_resolution_clock::now();
    int blocks = (n - 2 + block_size - 1) / block_size;
    int waves = 2 * blocks - 1;
    while (max_diff > eps) {
        max_diff = 0;
        for (int wave = 0; wave < waves; wave++) {
#pragma omp parallel for reduction(max:max_diff) schedule(static)
            for (int block_i = 0; block_i < blocks; block_i++) {
                int block_j = wave - block_i;
                if (block_j < 0 || block_j >= blocks){
                    continue;
                }
                int start_i = 1 + block_i * block_size;
                int start_j = 1 + block_j * block_size;
                int end_i = std::min(start_i + block_size, n - 1);
                int end_j = std::min(start_j + block_size, n - 1);
                for (int i = start_i; i < end_i; i++) {
                    for (int j = start_j; j < end_j; j++){
                        double x = i * h;
                        double y  = j * h;
                        double f = -2.0 * M_PI * M_PI * sin(M_PI*x) * sin(M_PI*y);
                        double old_value = v[i][j];
                        double new_value = (v[i-1][j] + v[i+1][j] + v[i][j-1] + v[i][j+1] - h2*f) / 4.0;
                        v[i][j] = new_value;
                        double diff = std::abs(new_value - old_value);
                        max_diff = std::max(max_diff, diff);
                    }
                }
            }
        } 
    }
    auto end = std::chrono::high_resolution_clock::now();
    double elapsed = std::chrono::duration<double>(end - start).count();
    std::cout << elapsed << std::endl;
}