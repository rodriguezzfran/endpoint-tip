CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++14 -pedantic -g

SRC = increment.cpp
HDR = increment.h
TEST_SRC = test_increment.cpp
TEST_BIN = test_increment
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all

.PHONY: all test run memcheck clean

all: test

test: $(TEST_BIN)

$(TEST_BIN): $(SRC) $(TEST_SRC) $(HDR)
	$(CXX) $(CXXFLAGS) $(SRC) $(TEST_SRC) -lgtest -lgtest_main -pthread -o $(TEST_BIN)

run: test
	./$(TEST_BIN)

memcheck: test
	$(VALGRIND) ./$(TEST_BIN)

clean:
	rm -f $(TEST_BIN)
