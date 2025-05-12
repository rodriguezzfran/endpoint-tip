CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic -g # -g for debugging

SRC = state_machine.c
TARGET = state_machine	

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

memcheck: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)
