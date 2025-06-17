#ifndef LIST_H
#define LIST_H

#include "entity.h"
#include <stddef.h>



typedef struct {
    GameGenre *data;  /// Вказівник на масив жанрів
    size_t size;
    size_t capacity;
} GameGenreList;

void list_init(GameGenreList *list);
void list_free(GameGenreList *list);
int list_push_back(GameGenreList *list, const GameGenre *genre);
int list_remove_at(GameGenreList *list, size_t index);
void list_print(const GameGenreList *list);
int list_find_by_name(const GameGenreList *list, const char *name, GameGenreList *result);
void list_sort_by_popularity(GameGenreList *list);

#endif
