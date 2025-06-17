/* #include "../src/list.h"
#include <assert.h>
#include <string.h>

void test_push_back_and_size() {
    GameGenreList list;
    list_init(&list);
    GameGenre g = {"RPG", 90, "Role-playing game"};
    assert(list_push_back(&list, &g));
    assert(list.size == 1);
    assert(strcmp((list.data)->name, "RPG") == 0);
    list_free(&list);
}

void test_remove_at() {
    GameGenreList list;
    list_init(&list);
    GameGenre g1 = {"RPG", 90, "Role-playing game"};
    GameGenre g2 = {"FPS", 80, "Shooter"};
    list_push_back(&list, &g1);
    list_push_back(&list, &g2);
    assert(list_remove_at(&list, 0));
    assert(list.size == 1);
    assert(strcmp((list.data)->name, "FPS") == 0);
    list_free(&list);
}

void test_find_by_name() {
    GameGenreList list;
    list_init(&list);
    GameGenre g1 = {"RPG", 90, "Role-playing game"};
    GameGenre g2 = {"FPS", 80, "Shooter"};
    GameGenre g3 = {"RPG", 85, "Another RPG"};
    list_push_back(&list, &g1);
    list_push_back(&list, &g2);
    list_push_back(&list, &g3);
    GameGenreList found;
    int cnt = list_find_by_name(&list, "RPG", &found);
    assert(cnt == 2);
    assert(strcmp((found.data)->name, "RPG") == 0);
    list_free(&found);
    list_free(&list);
}

void test_sort() {
    GameGenreList list;
    list_init(&list);
    GameGenre g1 = {"RPG", 30, "Role-playing game"};
    GameGenre g2 = {"FPS", 90, "Shooter"};
    GameGenre g3 = {"Strategy", 80, "Strategic"};
    list_push_back(&list, &g1);
    list_push_back(&list, &g2);
    list_push_back(&list, &g3);
    list_sort_by_popularity(&list);
    assert((list.data)->popularity == 90);
    list_free(&list);
}

int main() {
    test_push_back_and_size();
    test_remove_at();
    test_find_by_name();
    test_sort();
    printf("All tests passed!\n");
    return 0;
} */
