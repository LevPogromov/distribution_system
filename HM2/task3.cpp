#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <chrono>
int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cout << "Using: ./task3 <size of grid> <c> <eps>\n";
        return 1;
    }
    int n = strtol(argv[1], NULL, 10);
    double c = strtod(argv[2], nullptr);
    double eps = strtod(argv[3], nullptr);
    double h = 1.0 / (n-1);
    double h2 = h * h;
    std::vector<std::vector<double>>v(n, std::vector<double>(n,c));
    double max_diff = __INT_MAX__;
    auto start = std::chrono::high_resolution_clock::now();
    while (max_diff > eps) {
        max_diff = 0;
        for (int i = 1; i < n-1; i++) {
            for (int j = 1; j < n-1; j++){
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
    auto end = std::chrono::high_resolution_clock::now();
    double elapsed = std::chrono::duration<double>(end - start).count();
    std::cout << elapsed << std::endl;
}