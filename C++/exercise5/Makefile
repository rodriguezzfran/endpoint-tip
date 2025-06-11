CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++17 -pedantic -g

SRC = state_pattern.cpp
HDR = state_pattern.h

TEST_SRC = test_state_pattern.cpp
TEST_BIN = state_pattern_test

RUN_BIN = run_fsm

VALGRIND = valgrind --leak-check=full --show-leak-kinds=all

.PHONY: all test run memcheck clean

all: run

test: $(TEST_BIN)
	./$(TEST_BIN)

$(TEST_BIN): $(TEST_SRC) $(HDR)
	$(CXX) $(CXXFLAGS) $(TEST_SRC) -lgtest -lgmock -lgtest_main -pthread -o $(TEST_BIN)

run: $(SRC) $(HDR)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(RUN_BIN)
	./$(RUN_BIN)

memcheck: $(TEST_BIN)
	$(VALGRIND) ./$(TEST_BIN)

clean:
	rm -f $(TEST_BIN) $(RUN_BIN)
