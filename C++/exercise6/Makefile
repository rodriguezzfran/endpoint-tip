CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -pedantic -g

SRC = friends_group.cpp
HDR = friends_group.hpp

TEST_SRC = test_friends_group.cpp
TEST_BIN = friends_group_test

RUN_BIN = friends_group

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
