
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node* list_read(const char* filename) {
    FILE* f = fopen(filename, "r");
    if (!f) return NULL;
    int n;
    if (fscanf(f, "%d\n", &n) != 1) { fclose(f); return NULL; }
    Node* head = NULL;
    for (int i = 0; i < n; ++i) {
        GameGenre temp;
        if (fscanf(f, "%63[^;];%d;%127[^\n]\n", temp.name, &temp.popularity, temp.description) != 3)
            break;
        head = list_push_back(head, &temp);
    }
    fclose(f);
    return head;
}

int list_write(const char* filename, Node* head) {
    FILE* f = fopen(filename, "w");
    if (!f) return 0;
    int count = 0;
    for (Node* p = head; p; p = p->next) count++;
    fprintf(f, "%d\n", count);
    for (Node* p = head; p; p = p->next)
        fprintf(f, "%s;%d;%s\n", p->data.name, p->data.popularity, p->data.description);
    fclose(f);
    return 1;
}

void list_print(Node* head) {
    for (Node* p = head; p; p = p->next)
        printf("Жанр: %s | Популярність: %d | Опис: %s\n", p->data.name, p->data.popularity, p->data.description);
}

void list_free(Node* head) {
    while (head) {
        Node* next = head->next;
        free(head);
        head = next;
    }
}

Node* list_push_back(Node* head, const GameGenre* value) {
    Node* node = malloc(sizeof(Node));
    if (!node) return head;
    node->data = *value;
    node->next = NULL;
    if (!head) return node;
    Node* p = head;
    while (p->next) p = p->next;
    p->next = node;
    return head;
}

Node* list_remove_at(Node* head, size_t index) {
    if (!head) return NULL;
    if (index == 0) {
        Node* next = head->next;
        free(head);
        return next;
    }
    Node* p = head;
    for (size_t i = 0; p->next && i < index - 1; ++i, p = p->next);
    if (p->next) {
        Node* to_del = p->next;
        p->next = to_del->next;
        free(to_del);
    }
    return head;
}

Node* list_sort_by_popularity(Node* head) {
    if (!head || !head->next) return head;
    Node *sorted = NULL;
    while (head) {
        Node *max_prev = NULL, *max = head, *prev = head, *cur = head->next;
        while (cur) {
            if (cur->data.popularity > max->data.popularity) {
                max_prev = prev;
                max = cur;
            }
            prev = cur;
            cur = cur->next;
        }
        if (max_prev) max_prev->next = max->next;
        else head = max->next;
        max->next = sorted;
        sorted = max;
    }
    // розвертаємо список
    Node *rev = NULL;
    while (sorted) {
        Node *next = sorted->next;
        sorted->next = rev;
        rev = sorted;
        sorted = next;
    }
    return rev;
}

Node* list_find_by_name(Node* head, const char* name, Node** found_head) {
    Node* found = NULL;
    Node** tail = &found;
    for (Node* p = head; p; p = p->next) {
        if (strcmp(p->data.name, name) == 0) {
            Node* n = malloc(sizeof(Node));
            n->data = p->data;
            n->next = NULL;
            *tail = n;
            tail = &n->next;
        }
    }
    if (found_head) *found_head = found;
    return found;
}
