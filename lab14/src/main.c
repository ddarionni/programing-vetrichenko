

#include "lib.h"
#include <stdio.h>
#define MAX_GENRES 100

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s assets/input.txt\n", argv[0]);
        return 1;
    }
    GameGenre arr[MAX_GENRES], found[MAX_GENRES];
    int n = 0, found_count = 0;

    if (!read_genres(argv[1], arr, &n)) {
        printf("Cannot read file!\n");
        return 2;
    }

    printf("Всі жанри:\n");
    print_genres(arr, n);

    printf("\nВідсортовано за популярністю:\n");
    sort_genres_by_popularity(arr, n);
    print_genres(arr, n);

    if (find_genres_by_name(arr, n, "RPG", found, &found_count) > 0) {
        printf("\nЗнайдено жанри з назвою RPG:\n");
        print_genres(found, found_count);
    } else {
        printf("\nЖанрів з назвою RPG не знайдено\n");
    }

    if (!write_genres("assets/output.txt", arr, n)) {
        printf("Cannot write to output file!\n");
        return 3;
    }

    return 0;
}
