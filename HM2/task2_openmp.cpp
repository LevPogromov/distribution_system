#include <iostream>
#include <omp.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    double x, y;
};

void sort_for_angle(vector <pair <double, double>>& v) {
    double cx = 0, cy = 0;

    for (const auto& p : v) {
        cx += p.first;
        cy += p.second;
    }

    cx /= v.size();
    cy /= v.size();

    sort(v.begin(), v.end(),
    [cx, cy](const pair <double, double>& a, const pair<double, double>& b) {
        double angleA = atan2(a.second - cy, a.first - cx);
        double angleB = atan2(b.second - cy, b.first - cx);

        return angleA < angleB;
    }
);
}

// \[D=(x_2-x_1)(y-y_1)-(y_2-y_1)(x-x_1)\]
double cross(pair <double, double>A, pair <double, double> B, pair <double, double> P) {
    return (B.first - A.first) * (P.second - A.second)
         - (B.second - A.second) * (P.first - A.first);
}


vector<pair<double, double>> parse_and_unit(vector<pair<double, double>> v1, vector<pair<double, double>> v2) {
    const double EPS = 1e-10;

    if (v1.empty()) return v2;
    if (v2.empty()) return v1;

    // cross(A, B, P) > 0:
    // P находится слева от направленной прямой A -> B.

    // Площадь ориентированного многоугольника.
    auto signed_area = [](const vector<pair<double, double>>& v) {
        double area = 0;

        for (int i = 0; i < (int)v.size(); ++i) {
            int j = (i + 1) % v.size();

            area += v[i].first * v[j].second
                  - v[j].first * v[i].second;
        }

        return area;
    };

    // Для вырожденных оболочек (отрезки или точки)
    // используем отдельную обработку.
    auto build_hull = [&](vector<pair<double, double>> points) {
        sort(points.begin(), points.end());
        points.erase(unique(points.begin(), points.end()), points.end());

        if (points.size() <= 2) return points;

        vector<pair<double, double>> lower, upper;

        for (const auto& p : points) {
            while (lower.size() >= 2 &&
                cross(lower[lower.size() - 2],
                      lower[lower.size() - 1], p) <= EPS) {
                lower.pop_back();
            }
            lower.push_back(p);
        }

        for (int i = (int)points.size() - 1; i >= 0; --i) {
            const auto& p = points[i];

            while (upper.size() >= 2 &&
                cross(upper[upper.size() - 2],
                      upper[upper.size() - 1], p) <= EPS) {
                upper.pop_back();
            }
            upper.push_back(p);
        }

        lower.pop_back();
        upper.pop_back();

        lower.insert(lower.end(), upper.begin(), upper.end());

        return lower;
    };

    if (v1.size() < 3 || v2.size() < 3 ||
        abs(signed_area(v1)) < EPS ||
        abs(signed_area(v2)) < EPS) {

        vector<pair<double, double>> all = v1;
        all.insert(all.end(), v2.begin(), v2.end());

        return build_hull(all);
    }

    // Поиск общей опорной прямой.
    // v1 — L, v2 — R.
    //
    // upper = true: все точки должны лежать под прямой.
    // upper = false: все точки должны лежать над прямой.

    auto find_tangent = [&](bool upper, int& li, int& ri) {
        for (int i = 0; i < (int)v1.size(); ++i) {
            for (int j = 0; j < (int)v2.size(); ++j) {

                bool valid = true;

                // Проверяем все вершины L.
                for (const auto& p : v1) {
                    double c = cross(v1[i], v2[j], p);

                    if (upper ? c > EPS : c < -EPS) {
                        valid = false;
                        break;
                    }
                }

                if (!valid) continue;

                // Проверяем все вершины R.
                for (const auto& p : v2) {
                    double c = cross(v1[i], v2[j], p);

                    if (upper ? c > EPS : c < -EPS) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    li = i;
                    ri = j;
                    return true;
                }
            }
        }

        return false;
    };

    int ltop, rtop;
    int lbottom, rbottom;

    // Верхняя касательная.
    if (!find_tangent(true, ltop, rtop)) {
        cerr << "Не удалось найти верхнюю касательную\n";
        return {};
    }

    // Нижняя касательная.
    if (!find_tangent(false, lbottom, rbottom)) {
        cerr << "Не удалось найти нижнюю касательную\n";
        return {};
    }

    vector<pair<double, double>> ans;

    // Правая оболочка: от rbottom до rtop.
    for (int i = rbottom; ; i = (i + 1) % v2.size()) {
        ans.push_back(v2[i]);

        if (i == rtop) break;
    }

    // Левая оболочка: от ltop до lbottom.
    for (int i = ltop; ; i = (i + 1) % v1.size()) {
        ans.push_back(v1[i]);

        if (i == lbottom) break;
    }

    return ans;
}


void divide(vector<pair <double, double>>& points, vector<int>& groups) {
    int n = points.size();

    // Если в группе осталось 2 или 3 точки
    if (n <= 3) {
        groups.push_back(n);
        return;
    }

    // Находим медиану по X
    int mid = n / 2;

    nth_element(
        points.begin(),
        points.begin() + mid,
        points.end(),
        [](const pair <double, double>& a, const pair <double, double>& b) {
            return a.first < b.first;
        }
    );

    // Делим группу на две части
    vector<pair <double, double>> left(
        points.begin(),
        points.begin() + mid
    );

    vector<pair <double, double>> right(
        points.begin() + mid,
        points.end()
    );

    // Рекурсивно делим обе части
    divide(left, groups);
    divide(right, groups);
}

int main(int argc, char* argv[]) {
    long num_points;
    
    if (argc < 4) {
        printf("Using: ./task2_openmp <thread_count> <input_file_name> <output_file_name>\n");
        return 1;
    }
    int thread_count = strtol(argv[1], NULL, 10);

    freopen(argv[2], "r", stdin);
    freopen(argv[3], "w", stdout);

    cin >> num_points;

    vector <pair <double, double>> points(num_points);

    for (int i = 0; i < num_points; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    sort(points.begin(), points.end(), [](pair<double, double> a, pair <double, double> b) {
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    });
    vector <int> groups;
    divide(points, groups);
    vector <bool> acc_group(groups.size(), true);
    vector <int> rep(groups.size(), 0);
    for (int i = 1; i < groups.size(); ++i) {
        rep[i] += groups[i - 1] + rep[i - 1];
    }
vector<vector<pair<double, double>>> ans_points(groups.size());

#pragma omp parallel num_threads(thread_count)
{
    #pragma omp for
    for (int i = 0; i < groups.size(); ++i) {
        vector<pair<double, double>> point_v;

        for (int j = 0; j < groups[i]; ++j) {
            point_v.push_back(points[rep[i] + j]);
        }

        sort_for_angle(point_v);

        ans_points[i] = point_v;
    }

    for (int i = 0; i < (int)(ceil(log2(groups.size()))) + 1; ++i) {
#pragma omp for
        for (int j = 0; j < groups.size() - (1 << i); j += 1 << (i + 1)) {
            vector<pair<double, double>> ans_v =
                parse_and_unit(ans_points[j], ans_points[j + (1 << i)]);
            acc_group[j + (1 << i)] = false;

            ans_points[j] = ans_v;
        }
    }
}
// cout << num_points << endl;

// int it = 0;
// for (int i = 0; i < ans_points.size(); ++i) {
//     if (acc_group[i]) {
//         cout << "0 " << i << " " << ans_points[i].size() << endl;
//         for (int j = 0; j < ans_points[i].size(); ++j) {
//             cout << ans_points[i][j].first << " " << ans_points[i][j].second << endl;
//         }
//     }
// }
cout << ans_points[0].size() << endl;
for (pair<double, double> i : ans_points[0]) {
    cout << i.first << " " << i.second << endl;
}
}