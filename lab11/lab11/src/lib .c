#include "lib.h"

void multiply_matrices(int n, int m, int p, const double a[n][m], const double b[m][p], double c[n][p]) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < p; ++j) {
            c[i][j] = 0;
            for (int k = 0; k < m; ++k)
                c[i][j] += a[i][k] * b[k][j];
        }
}
