CC = gcc
CFLAGS = -Wall -Wextra -std=c11
OBJ = BinarySearchTree.o Set.o test_Set.o
TARGET = test_Set

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

BinarySearchTree.o: BinarySearchTree.c BinarySearchTree.h
	$(CC) $(CFLAGS) -c BinarySearchTree.c

Set.o: Set.c Set.h BinarySearchTree.h
	$(CC) $(CFLAGS) -c Set.c

test_Set.o: test_Set.c Set.h
	$(CC) $(CFLAGS) -c test_Set.c

clean:
	rm -f *.o $(TARGET)
