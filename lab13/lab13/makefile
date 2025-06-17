CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
SRC = src/main.c src/module.c
BIN = bin/main
TESTSRC = test/test.c src/module.c
TESTBIN = bin/test

all: $(BIN)

$(BIN): $(SRC) | bin
	$(CC) $(CFLAGS) -o $@ $(SRC)

bin:
	mkdir -p bin

run: $(BIN)
	./$(BIN)

test: $(TESTBIN)
	./$(TESTBIN)

$(TESTBIN): $(TESTSRC) | bin
	$(CC) $(CFLAGS) -o $@ $(TESTSRC)

doc:
	doxygen Doxyfile

clean:
	rm -rf bin *.o *.gcda *.gcno *.gcov doc/html

.PHONY: all run test doc clean
