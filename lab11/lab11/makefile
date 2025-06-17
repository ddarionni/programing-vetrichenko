CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
SRC = src/main.c src/yourmodule.c
OBJ = $(SRC:.c=.o)
BIN = bin/main

all: $(BIN)

$(BIN): $(SRC) | bin
	$(CC) $(CFLAGS) -o $@ $(SRC)

bin:
	mkdir -p bin

run: $(BIN)
	./$(BIN)

doc:
	doxygen Doxyfile

clean:
	rm -rf bin *.o *.gcda *.gcno *.gcov doc/html

.PHONY: all run doc clean
