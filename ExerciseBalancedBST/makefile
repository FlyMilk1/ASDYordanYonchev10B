# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Files
TARGET = BalancedBST.exe
SRCS = main.c BinarySearchTree.c LinkedList.c
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Link all object files into the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Compile each .c file into .o file

main.o: main.c BinarySearchTree.h
	$(CC) $(CFLAGS) -c main.c -o main.o

BinarySearchTree.o: BinarySearchTree.c BinarySearchTree.h LinkedList.h
	$(CC) $(CFLAGS) -c BinarySearchTree.c -o BinarySearchTree.o

LinkedList.o: LinkedList.c LinkedList.h
	$(CC) $(CFLAGS) -c LinkedList.c -o LinkedList.o

# Clean up
clean:
	rm -f *.o $(TARGET)
