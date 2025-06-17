/* #include "../src/module.h"
#include <assert.h>
#include <stdio.h>

// Тест додавання елемента
void test_add_element() {
    MyStruct arr;
    mystruct_init(&arr);
    mystruct_add(&arr, 123);
    assert(mystruct_size(&arr) == 1);
    assert(mystruct_get(&arr, 0) == 123);
    mystruct_free(&arr);
}

// Тест видалення елемента
void test_remove_element() {
    MyStruct arr;
    mystruct_init(&arr);
    mystruct_add(&arr, 1);
    mystruct_add(&arr, 2);
    mystruct_remove(&arr, 0);
    assert(mystruct_size(&arr) == 1);
    assert(mystruct_get(&arr, 0) == 2);
    mystruct_free(&arr);
}

int main() {
    test_add_element();
    test_remove_element();
    printf("All tests passed!\n");
    return 0;
}
*/
