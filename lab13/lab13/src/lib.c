#include "lib.h"

int find_max_in_matrix(FILE *in) {
    int n, m, num, max;
    if (fscanf(in, "%d%d", &n, &m) != 2) return 0;
    if (fscanf(in, "%d", &max) != 1) return 0;
    for (int i = 0; i < n; i++) {
        for (int j = (i==0 ? 1 : 0); j < m; j++) { 
            if (fscanf(in, "%d", &num) != 1) return 0;
            if (num > max) max = num;
        }
    }
    return max;
}
