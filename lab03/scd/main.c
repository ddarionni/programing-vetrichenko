#include <stdio.h> // Необхідно для використання функцій вводу/виводу

//Завдання: Підрахувати суму чисел у заданому діапазоні.
//Автор: Ветріченко Дарина Ігорівна
//Група: КН-924з
//Опис: Програма отримує початкове і кінцеве значення,обчислює суму всіх чисел у заданому діапазоні і виводить результат.

int main() {
   int start, end, sum = 0;

   // Введення початкового та кінцевого значення
    printf("Введіть початкове число: ");
   scanf("%d", &start);
   printf("Введіть кінцеве число: ");
   scanf("%d", &end);
   // Обчислення суми
    for (int i = start; i <= end; i++) {
        sum += i;
   }

    // Виведення результату
    printf("Сума чисел від %d до %d дорівнює %d\n", start, end, sum);

    return 0;
}
