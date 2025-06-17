CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g
GTEST_FLAGS = -lgtest -lgtest_main -pthread
SRC = src/entity.cpp src/list.cpp src/main.cpp
TESTSRC = test/test.cpp src/entity.cpp src/list.cpp

all: bin/main bin/test

bin/main: $(SRC) | bin
	$(CXX) $(CXXFLAGS) -o bin/main $(SRC)

bin/test: $(TESTSRC) | bin
	$(CXX) $(CXXFLAGS) -o bin/test $(TESTSRC) $(GTEST_FLAGS)

bin:
	mkdir -p bin

run: bin/main
	./bin/main

test: bin/test
	./bin/test

clean:
	rm -rf bin *.gcda *.gcno *.gcov

.PHONY: all run test clean
