CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic -g # -g for debugging

SRC = multi_languaje.c
TARGET = multi_languaje

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

memcheck: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)
