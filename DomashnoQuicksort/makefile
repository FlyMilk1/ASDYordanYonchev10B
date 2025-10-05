LinkedList.o: LinkedList.c LinkedList.h
	gcc -Wall -c LinkedList.c -o LinkedList.o
quicksort.o: quicksort.c LinkedList.h
	gcc -Wall -c quicksort.c -o quicksort.o
all: LinkedList.o quicksort.o
	gcc LinkedList.o quicksort.o -o quicksort.exe
clean:
	rm -f *.o quicksort.exe