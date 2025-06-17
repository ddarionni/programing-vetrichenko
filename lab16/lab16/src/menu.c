#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu() {
    Node* head = NULL;
    char fname[128] = "assets/input.txt";
    int running = 1;
    while (running) {
        printf("\n1. Прочитати з файлу\n");
        printf("2. Записати у файл\n");
        printf("3. Вивести список\n");
        printf("4. Додати жанр\n");
        printf("5. Видалити за індексом\n");
        printf("6. Знайти за назвою\n");
        printf("7. Сортувати за популярністю\n");
        printf("0. Вийти\n");
        printf(">> ");
        int ch; scanf("%d", &ch); getchar();
        if (ch == 1) {
            list_free(head);
            head = list_read(fname);
            printf(head ? "OK\n" : "Помилка читання\n");
        } else if (ch == 2) {
            if (list_write("assets/output.txt", head))
                printf("OK\n");
            else printf("Помилка запису\n");
        } else if (ch == 3) {
            list_print(head);
        } else if (ch == 4) {
            GameGenre g;
            printf("Назва: "); fgets(g.name, 64, stdin); g.name[strcspn(g.name, "\n")]=0;
            printf("Популярність: "); scanf("%d", &g.popularity); getchar();
            printf("Опис: "); fgets(g.description, 128, stdin); g.description[strcspn(g.description, "\n")]=0;
            head = list_push_back(head, &g);
        } else if (ch == 5) {
            printf("Введіть індекс: "); size_t idx; scanf("%zu", &idx); getchar();
            head = list_remove_at(head, idx);
        } else if (ch == 6) {
            printf("Введіть назву: "); char search[64]; fgets(search,64,stdin); search[strcspn(search,"\n")]=0;
            Node* found = NULL;
            list_find_by_name(head, search, &found);
            if (!found) printf("Не знайдено\n");
            else { list_print(found); list_free(found);}
        } else if (ch == 7) {
            head = list_sort_by_popularity(head);
            printf("Відсортовано!\n");
        } else if (ch == 0) {
            running = 0;
        }
    }
    list_free(head);
}
