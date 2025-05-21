CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -pedantic -g

# Archivos de código
SRC = state_pattern.cpp
HDR = state_pattern.hpp

# Archivos de testing
TEST_SRC = test_state_pattern.cpp
MOCK_HDR = mock_state_pattern.hpp
TEST_BIN = state_pattern_test

# Ejecutable de producción
RUN_BIN = run_fsm

VALGRIND = valgrind --leak-check=full --show-leak-kinds=all

.PHONY: all test run memcheck clean

all: run

# Compila y ejecuta los tests
test: $(TEST_BIN)
	./$(TEST_BIN)

# Compila el ejecutable de tests
$(TEST_BIN): $(TEST_SRC) $(MOCK_HDR) $(HDR)
	$(CXX) $(CXXFLAGS) $(TEST_SRC) -lgtest -lgmock -lgtest_main -pthread -o $(TEST_BIN)

# Compila y ejecuta el programa principal
run: $(SRC) $(HDR)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(RUN_BIN)
	./$(RUN_BIN)

# Ejecuta los tests con valgrind
memcheck: $(TEST_BIN)
	$(VALGRIND) ./$(TEST_BIN)

clean:
	rm -f $(TEST_BIN) $(RUN_BIN)
