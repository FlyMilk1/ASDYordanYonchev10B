LinkedList.o: LinkedList.c LinkedList.h
	gcc -Wall -c LinkedList.c -o LinkedList.o
BinarySearchTree.o: BinarySearchTree.c LinkedList.h
	gcc -Wall -c BinarySearchTree.c -o BinarySearchTree.o
all: BinarySearchTree.o
	gcc BinarySearchTree.o -o BalancedBST.exe
clean:
	rm -f *.o BalancedBST.exe