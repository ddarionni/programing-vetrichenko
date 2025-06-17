#include "lib.h"
#include <stdio.h>
#include <stdlib.h>

void print_author_info();

int main(void) {
    print_author_info();

    int n, m, p;
    printf("Введіть кількість рядків першої матриці: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Некоректне число рядків!\n");
        return 1;
    }
    printf("Введіть кількість стовпців першої матриці (і рядків другої): ");
    if (scanf("%d", &m) != 1 || m <= 0) {
        printf("Некоректне число стовпців!\n");
        return 1;
    }
    printf("Введіть кількість стовпців другої матриці: ");
    if (scanf("%d", &p) != 1 || p <= 0) {
        printf("Некоректне число стовпців другої матриці!\n");
        return 1;
    }

    double a[n][m], b[m][p], c[n][p];

    printf("Введіть елементи першої матриці (%dx%d):\n", n, m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (scanf("%lf", &a[i][j]) != 1 || a[i][j] < -1000 || a[i][j] > 1000) {
                printf("Некоректне число! Допустимий діапазон: (-1000; 1000)\n");
                return 2;
            }
        }

    printf("Введіть елементи другої матриці (%dx%d):\n", m, p);
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < p; ++j) {
            if (scanf("%lf", &b[i][j]) != 1 || b[i][j] < -1000 || b[i][j] > 1000) {
                printf("Некоректне число! Допустимий діапазон: (-1000; 1000)\n");
                return 3;
            }
        }

    multiply_matrices(n, m, p, a, b, c);

    printf("Результат добутку:\n");
    for (int i = 0; i < n; ++i) {
        printf("[");
        for (int j = 0; j < p; ++j) {
            printf("%8.2lf", c[i][j]);
            if (j < p-1) printf(" ");
        }
        printf(" ]\n");
    }

    return 0;
}
void print_author_info() {
    printf("Лабораторна робота №11\n");
    printf("Ветріченко Дарина, КН-924з\n");
    printf("Тема: Добуток двох матриць\n\n");
}
