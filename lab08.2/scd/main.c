
#include <stdio.h>
#include <stdlib.h> // Для функцій atoi() і rand()

// Функція для перевірки, чи є число простим
int isPrime(int number) {
    if (number < 2) return 0; // Число не є простим
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) return 0; // Знайдено дільник
    }
    return 1; // Число просте
}

int main(int argc, char *argv[]) {
    int number = (argc > 1) ? atoi(argv[1]) : 29; // Отримання числа з аргументів або значення за замовчуванням
    int randomNumber = rand() % 100 + 1; // Генерація випадкового числа

    // Виведення результатів
    printf("Перевірка числа %d: %s\n", number, isPrime(number) ? "Просте" : "Не просте");
    printf("Перевірка випадкового числа %d: %s\n", randomNumber, isPrime(randomNumber) ? "Просте" : "Не просте");

    return 0;
}

 