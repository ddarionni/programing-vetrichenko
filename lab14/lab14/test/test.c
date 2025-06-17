 /* #include "../src/module.h"
#include <assert.h>
#include <stdio.h>

//dodavanya
void test_add_element() {
    MyStruct arr;
    mystruct_init(&arr);
    mystruct_add(&arr, 10);
    assert(mystruct_size(&arr) == 1);
    assert(mystruct_get(&arr, 0) == 10);
    mystruct_free(&arr);
}

// -
void test_remove_element() {
    MyStruct arr;
    mystruct_init(&arr);
    mystruct_add(&arr, 5);
    mystruct_add(&arr, 8);
    mystruct_remove(&arr, 0);
    assert(mystruct_size(&arr) == 1);
    assert(mystruct_get(&arr, 0) == 8);
    mystruct_free(&arr);
}

// poshuk
void test_find_element() {
    MyStruct arr;
    mystruct_init(&arr);
    mystruct_add(&arr, 100);
    mystruct_add(&arr, 200);
    int idx = mystruct_find(&arr, 200);
    assert(idx == 1);
    mystruct_free(&arr);
}

int main() {
    test_add_element();
    test_remove_element();
    test_find_element();
    printf("All tests passed!\n");
    return 0;
}
*/
