CC=gcc
CFLAGS=-Wall -Wextra -std=c99 -g
INC=-Isrc

all: bin/main bin/test

bin/main: src/main.c src/list.c src/entity.h src/list.h | bin
	$(CC) $(CFLAGS) $(INC) -o bin/main src/main.c src/list.c

bin/test: test/test.c src/list.c src/entity.h src/list.h | bin
	$(CC) $(CFLAGS) $(INC) -o bin/test test/test.c src/list.c

bin:
	mkdir -p bin

doc:
	doxygen Doxyfile

clean:
	rm -rf bin *.gcda *.gcno *.gcov doc/html

coverage: bin/test
	$(CC) $(CFLAGS) --coverage test/test.c src/list.c -o bin/test_cov
	./bin/test_cov
	gcov src/list.c

valgrind: bin/test
	valgrind --leak-check=full ./bin/test

.PHONY: all doc clean coverage valgrind
