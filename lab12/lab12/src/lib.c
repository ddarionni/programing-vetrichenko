#include "lib.h"
#include <ctype.h>

size_t count_words_in_line(const char *line) {
    size_t count = 0;
    int in_word = 0;
    while (*line) {
        if (isspace((unsigned char)*line)) {
            in_word = 0;
        } else if (!in_word) {
            ++count;
            in_word = 1;
        }
        ++line;
    }
    return count;
}   
