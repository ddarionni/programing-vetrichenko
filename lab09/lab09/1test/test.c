/*#include "lib.h"
#include <check.h>
#include <stdlib.h>

START_TEST(test_sum)
{
    #define DATA_SIZE_SUM 3
    int input_data_a[] = { 1, 3, -1 };
    int input_data_b[] = { 2, 0, 10 };
    int expected_values[] = { 3, 3, 9 };
    for (int i = 0; i < DATA_SIZE_SUM; i++) {
        int actual_value = sum(input_data_a[i], input_data_b[i]);
        ck_assert_int_eq(expected_values[i], actual_value);
    }
}
END_TEST

Suite *sum_suite(void)
{
    Suite *s = suite_create("Lab09");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_sum);
    suite_add_tcase(s, tc_core);
    return s;
}

*/

