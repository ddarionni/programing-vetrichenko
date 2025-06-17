#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INITIAL_CAPACITY 4

void list_init(GameGenreList *list) {
    list->data = malloc(INITIAL_CAPACITY * sizeof(GameGenre));
    list->size = 0;
    list->capacity = (list->data) ? INITIAL_CAPACITY : 0;
}

void list_free(GameGenreList *list) {
    free(list->data);
    list->data = NULL;
    list->size = 0;
    list->capacity = 0;
}

int list_push_back(GameGenreList *list, const GameGenre *genre) {
    if (list->size == list->capacity) {
        size_t new_capacity = (list->capacity == 0) ? INITIAL_CAPACITY : list->capacity * 2;
        GameGenre *tmp = realloc(list->data, new_capacity * sizeof(GameGenre));
        if (!tmp) return 0;
        list->data = tmp;
        list->capacity = new_capacity;
    }
    *(list->data + list->size) = *genre;
    list->size++;
    return 1;
}

int list_remove_at(GameGenreList *list, size_t index) {
    if (index >= list->size) return 0;
    GameGenre *dst = list->data + index;
    GameGenre *src = dst + 1;
    size_t count = list->size - index - 1;
    if (count > 0) {
        memmove(dst, src, count * sizeof(GameGenre));
    }
    list->size--;
    return 1;
}

void list_print(const GameGenreList *list) {
    const GameGenre *p = list->data;
    for (size_t i = 0; i < list->size; ++i, ++p) {
        printf("Жанр: %s | Популярність: %d | Опис: %s\n", p->name, p->popularity, p->description);
    }
}

int list_find_by_name(const GameGenreList *list, const char *name, GameGenreList *result) {
    list_init(result);
    const GameGenre *p = list->data;
    for (size_t i = 0; i < list->size; ++i, ++p) {
        if (strcmp(p->name, name) == 0) {
            list_push_back(result, p);
        }
    }
    return (int)result->size;
}

static int cmp_popularity(const void *a, const void *b) {
    int p1 = ((const GameGenre*)a)->popularity;
    int p2 = ((const GameGenre*)b)->popularity;
    return p2 - p1;
}

void list_sort_by_popularity(GameGenreList *list) {
    qsort(list->data, list->size, sizeof(GameGenre), cmp_popularity);
}
