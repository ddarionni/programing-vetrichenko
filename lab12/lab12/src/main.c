#include "lib.h"
#include <stdio.h>

#define BUF_SIZE 1000

int main(void) {
    printf("Лабораторна робота №12\n");
    printf("Ветріченко Дарина, КН-924з\n");
    printf("Тема: Робота з рядками (C-рядки)\n\n");
    printf("Введіть текст (до 1000 символів):\n");

    char buf[BUF_SIZE];
    while (fgets(buf, BUF_SIZE, stdin)) {
        size_t words = count_words_in_line(buf);
        printf("У цьому рядку %zu слів(а).\n", words);
    }

    return 0;
}
