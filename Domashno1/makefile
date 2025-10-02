LinkedList.o: LinkedList.c LinkedList.h
	gcc -Wall -c LinkedList.c -o LinkedList.o
main.o: main.c LinkedList.h
	gcc -Wall -c main.c -o main.o
all: LinkedList.o main.o
	gcc LinkedList.o main.o -o main.exe
clean:
	rm -f *.o main.exe