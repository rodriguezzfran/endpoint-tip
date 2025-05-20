CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic -g

SRC_ONE = state_machine.c
SRC_TWO = state_machine_w_func_pointer.c
HDR = state_machine.h
TARGET = state_machine

all: $(TARGET)

$(TARGET): $(SRC_ONE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC_ONE) $(HDR)

run: $(TARGET)
	./$(TARGET)

run_two: state_machine_two
	./state_machine_two

state_machine_two: $(SRC_TWO) $(HDR)
	$(CC) $(CFLAGS) -o state_machine_two $(SRC_TWO) $(HDR)

clean:
	rm -f $(TARGET) state_machine_two

memcheck_one: state_machine
	valgrind --leak-check=full --show-leak-kinds=all ./state_machine

memcheck_two: state_machine_two
	valgrind --leak-check=full --show-leak-kinds=all ./state_machine_two
