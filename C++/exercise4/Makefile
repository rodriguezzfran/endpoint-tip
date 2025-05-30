CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++17 -pedantic -g

SRC = obj_dialogue.cpp
HDR = obj_dialogue.h

TEST_SRC = test_obj_dialogue.cpp
MOCK_HDR = mock_obj_dialogue.h
TEST_BIN = obj_dialogue_test

RUN_BIN = run_dialogue

VALGRIND = valgrind --leak-check=full --show-leak-kinds=all

.PHONY: all test run memcheck clean

all: run

test: $(TEST_BIN)
	./$(TEST_BIN)

$(TEST_BIN): $(TEST_SRC) $(MOCK_HDR) $(HDR)
	$(CXX) $(CXXFLAGS) $(TEST_SRC) -lgtest -lgmock -lgtest_main -pthread -o $(TEST_BIN)

run: $(SRC) $(HDR)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(RUN_BIN)
	./$(RUN_BIN)

memcheck: $(RUN_BIN)
	$(VALGRIND) ./$(RUN_BIN)

clean:
	rm -f $(TEST_BIN) $(RUN_BIN)
