CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++14 -pedantic -g


HDR = state_pattern.hpp
TEST_SRC = state_pattern.cpp
TEST_BIN = state_pattern_test
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all

.PHONY: all test run memcheck clean

all: test

test: $(TEST_BIN)

$(TEST_BIN): $(TEST_SRC) $(HDR)
	$(CXX) $(CXXFLAGS) $(SRC) $(TEST_SRC) -lgtest -lgtest_main -pthread -o $(TEST_BIN)

run: test
	./$(TEST_BIN)

memcheck: test
	$(VALGRIND) ./$(TEST_BIN)

clean:
	rm -f $(TEST_BIN)
