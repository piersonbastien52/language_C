CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -fstack-protector -Iinclude
TARGET = Project


SRC = $(wildcard *.c */*.c */*/*.c) 

build:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) 

run:
	./$(TARGET)
clean:
	rm -f $(TARGET)