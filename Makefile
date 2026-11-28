
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Isrc

SRC = src/main.c src/algorithm.c src/utilities.c

TARGET = simulator
TEST_TARGET = test

all: $(TARGET)

$(TARGET): $(SRC) src/project.h
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

$(TEST_TARGET): tests/test.c src/algorithm.c src/utilities.c src/project.h
	$(CC) $(CFLAGS) tests/test.c src/algorithm.c src/utilities.c -o $(TEST_TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET)

.PHONY: all test clean
