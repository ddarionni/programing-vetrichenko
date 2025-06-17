CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
SRC = src/lib.c src/main.c
TEST_SRC = test/test.c src/lib.c
DIST = dist
BIN = main.bin
TEST_BIN = test.bin

.PHONY: all clean compile test prep

all: compile

prep:
	mkdir -p $(DIST)

compile: prep
	$(CC) $(CFLAGS) src/main.c src/lib.c -o $(DIST)/$(BIN)
	$(CC) $(CFLAGS) $(TEST_SRC) -o $(DIST)/$(TEST_BIN) -lcheck -fprofile-instr-generate -fcoverage-mapping

test: clean prep compile
	LLVM_PROFILE_FILE="$(DIST)/test.profraw" ./$(DIST)/$(TEST_BIN)
	llvm-profdata merge -sparse $(DIST)/test.profraw -o $(DIST)/test.profdata
	llvm-cov report $(DIST)/$(TEST_BIN) -instr-profile=$(DIST)/test.profdata src/lib.c
	llvm-cov show $(DIST)/$(TEST_BIN) -instr-profile=$(DIST)/test.profdata src/lib.c --format html > $(DIST)/coverage.html

clean:
	rm -rf $(DIST)
