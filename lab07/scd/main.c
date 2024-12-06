
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

 //другий код
   
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Функція для підрахунку слів
int countWords(const char *text) {
    int wordCount = 0;
    int inWord = 0;

    while (*text) {
        if (isspace(*text)) {
            inWord = 0; // Вийшли з слова
        } else if (!inWord) {
            inWord = 1; // Увійшли в слово
            wordCount++;
        }
        text++;
    }

    return wordCount;
}

int main(int argc, char *argv[]) {
    const char *text = (argc > 1) ? argv[1] : "Це текст для підрахунку слів за умовчанням.";

    // Виведення тексту та кількості слів
    printf("Текст: %s\n", text);
    printf("Кількість слів: %d\n", countWords(text));

    // Генерація випадкового тексту для демонстрації
    const char *randomText = "Випадковий текст для перевірки функції.";
    printf("Випадковий текст: %s\n", randomText);
    printf("Кількість слів у випадковому тексті: %d\n", countWords(randomText));

    return 0;
}


