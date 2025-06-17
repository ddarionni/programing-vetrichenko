#include "entity.h"
#include <stddef.h>
#ifndef LIST_H
#define LIST_H
typedef struct Node {
    GameGenre data;
    struct Node* next;
} Node;

// Основні функції для роботи зі списком:
Node* list_read(const char* filename);
int list_write(const char* filename, Node* head);
void list_print(Node* head);
void list_free(Node* head);

Node* list_push_back(Node* head, const GameGenre* value);
Node* list_remove_at(Node* head, size_t index);
Node* list_sort_by_popularity(Node* head);
Node* list_find_by_name(Node* head, const char* name, Node** found_head);

#endif
