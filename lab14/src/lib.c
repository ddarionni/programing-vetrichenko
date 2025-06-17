#include "lib.h"
#include <string.h>

int read_genres(const char *filename, GameGenre *arr, int *n) {
    FILE *fin = fopen(filename, "r");
    if (!fin) return 0;
    if (fscanf(fin, "%d\n", n) != 1) { fclose(fin); return 0; }
    GameGenre *p = arr;
    for (int i = 0; i < *n; i++, p++) {
        if (fscanf(fin, "%63[^;];%d;%127[^\n]\n", p->name, &p->popularity, p->description) != 3) {
            fclose(fin);
            return 0;
        }
    }
    fclose(fin);
    return 1;
}

int write_genres(const char *filename, const GameGenre *arr, int n) {
    FILE *fout = fopen(filename, "w");
    if (!fout) return 0;
    fprintf(fout, "%d\n", n);
    const GameGenre *p = arr;
    for (int i = 0; i < n; i++, p++) {
        fprintf(fout, "%s;%d;%s\n", p->name, p->popularity, p->description);
    }
    fclose(fout);
    return 1;
}

void print_genres(const GameGenre *arr, int n) {
    const GameGenre *p = arr;
    for (int i = 0; i < n; i++, p++) {
        printf("Жанр: %s | Популярність: %d | Опис: %s\n", p->name, p->popularity, p->description);
    }
}

int find_genres_by_name(const GameGenre *arr, int n, const char *name, GameGenre *result, int *found_count) {
    *found_count = 0;
    const GameGenre *p = arr;
    for (int i = 0; i < n; i++, p++) {
        if (strcmp(p->name, name) == 0) {
            *(result + *found_count) = *p;
            (*found_count)++;
        }
    }
    return *found_count;
}

int cmp_popularity(const void *a, const void *b) {
    int p1 = ((const GameGenre*)a)->popularity;
    int p2 = ((const GameGenre*)b)->popularity;
    return (p2 - p1); // Від більшого до меншого
}

void sort_genres_by_popularity(GameGenre *arr, int n) {
    qsort(arr, n, sizeof(GameGenre), cmp_popularity);
}
