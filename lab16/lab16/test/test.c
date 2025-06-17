/* #include "../src/list.h"
#include <assert.h>
#include <string.h>

void test_push_and_print() {
    Node* head = NULL;
    GameGenre g = {"RPG", 90, "Role"};
    head = list_push_back(head, &g);
    assert(head && strcmp(head->data.name, "RPG")==0);
    list_free(head);
}

void test_remove() {
    Node* head = NULL;
    GameGenre g1 = {"RPG", 90, "Role"};
    GameGenre g2 = {"FPS", 80, "Shooter"};
    head = list_push_back(head, &g1);
    head = list_push_back(head, &g2);
    head = list_remove_at(head, 0);
    assert(head && strcmp(head->data.name, "FPS")==0);
    list_free(head);
}

void test_sort() {
    Node* head = NULL;
    GameGenre g1 = {"RPG", 30, "Role"};
    GameGenre g2 = {"FPS", 90, "Shooter"};
    head = list_push_back(head, &g1);
    head = list_push_back(head, &g2);
    head = list_sort_by_popularity(head);
    assert(head->data.popularity == 90);
    list_free(head);
}

void test_find() {
    Node* head = NULL;
    GameGenre g1 = {"RPG", 30, "Role"};
    GameGenre g2 = {"FPS", 90, "Shooter"};
    GameGenre g3 = {"RPG", 85, "Another"};
    head = list_push_back(head, &g1);
    head = list_push_back(head, &g2);
    head = list_push_back(head, &g3);
    Node* found = NULL;
    int cnt = 0;
    for (Node* p = list_find_by_name(head,"RPG",&found); p; p = p->next) cnt++;
    assert(cnt == 2);
    list_free(found);
    list_free(head);
}

int main() {
    test_push_and_print();
    test_remove();
    test_sort();
    test_find();
    printf("All tests passed!\n");
    return 0;
}
*/
