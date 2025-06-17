

#include <stdio.h>
#include "lib.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("відкритиииии %s input.txt output.txt\n", argv[0]);
        return 1;
    }
    FILE *fin = fopen(argv[1], "r");
    if (!fin) {
        printf("неможливо відкрити файл для читання!\n");
        return 2;
    }
    int max = find_max_in_matrix(fin);
    fclose(fin);

    FILE *fout = fopen(argv[2], "w");
    if (!fout) {
        printf("не можливо відкрити!\n");
        return 3;
    }
    fprintf(fout, "%d\n", max);
    fclose(fout);
    return 0;
}
