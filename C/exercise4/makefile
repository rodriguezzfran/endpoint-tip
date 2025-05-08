CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic -g # -g for debugging

SRC = genericList.c
HDR = genericList.h
TARGET = genericList

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(HDR)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

memcheck: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)
