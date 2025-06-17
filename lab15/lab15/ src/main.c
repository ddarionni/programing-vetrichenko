#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    GameGenreList list;
    list_init(&list);

    GameGenre g1 = {"RPG", 90, "Role-playing game"};
    GameGenre g2 = {"FPS", 80, "First-person shooter"};
    GameGenre g3 = {"Strategy", 70, "Strategic gameplay"};
    GameGenre g4 = {"RPG", 95, "Another RPG"};

    list_push_back(&list, &g1);
    list_push_back(&list, &g2);
    list_push_back(&list, &g3);
    list_push_back(&list, &g4);

    printf("Всі жанри:\n");
    list_print(&list);

    printf("\nВидаляємо жанр з індексом 1\n");
    list_remove_at(&list, 1);
    list_print(&list);

    printf("\nВідсортовано за популярністю:\n");
    list_sort_by_popularity(&list);
    list_print(&list);

    printf("\nЖанри з назвою RPG:\n");
    GameGenreList found;
    list_find_by_name(&list, "RPG", &found);
    list_print(&found);
    list_free(&found);

    list_free(&list);
    return 0;
}
