#include "lib.h"

void reorder_by_sign(const double* arr, size_t n, double* out) {
    double* p_out = out;

   
    for (const double* p = arr; p < arr + n; ++p) {
        if (*p > 0) {
            *p_out = *p;
            ++p_out;
        }
    }

    for (const double* p = arr; p < arr + n; ++p) {
        if (*p == 0) {
            *p_out = *p;
            ++p_out;
        }
    }

    for (const double* p = arr; p < arr + n; ++p) {
        if (*p < 0) {
            *p_out = *p;
            ++p_out;
        }
    }
}
