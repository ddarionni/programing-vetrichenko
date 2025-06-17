
#ifndef LIB_H
#define LIB_H

#include <stdio.h>

typedef struct {
    char name[64];
    int popularity;
    char description[128];
} GameGenre;


int read_genres(const char *filename, GameGenre *arr, int *n);


int write_genres(const char *filename, const GameGenre *arr, int n);


void print_genres(const GameGenre *arr, int n);


int find_genres_by_name(const GameGenre *arr, int n, const char *name, GameGenre *result, int *found_count);


void sort_genres_by_popularity(GameGenre *arr, int n);

#endif
