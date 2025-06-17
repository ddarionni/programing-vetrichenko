#include "lib.h"
#include <assert.h>

void test_reorder_by_sign() {
    double arr[8] = {0.0, -2.2, 3.1, 0.0, -5.5, 4.4, 0.0, 7.7};
    double out[8];
    reorder_by_sign(arr, 8, out);

    assert(out[0] == 3.1);
    assert(out[1] == 4.4);
    assert(out[2] == 7.7);
    assert(out[3] == 0.0);
    assert(out[4] == 0.0);
    assert(out[5] == 0.0);
    assert(out[6] == -2.2);
    assert(out[7] == -5.5); //дебаг для перевірки
}

int main(void) {
    test_reorder_by_sign();
    
    return 0;
}
