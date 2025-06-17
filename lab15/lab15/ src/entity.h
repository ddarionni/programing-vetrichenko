#ifndef ENTITY_H
#define ENTITY_H


//Структура, що представляє жанр гри.

typedef struct {
    char name[64];        ///< Назва жанру
    int popularity;       ///< Популярність (0..100)
    char description[128];///< Опис
} GameGenre;

#endif
