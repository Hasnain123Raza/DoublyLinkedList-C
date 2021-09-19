all: driver build


driver: src/driver.c src/DoublyLinkedList.c
	mkdir bin
	gcc src/driver.c src/DoublyLinkedList.c -Iincludes -o bin/driver

build: src/DoublyLinkedList.c
	mkdir build
	gcc -c src/DoublyLinkedList.c -Iincludes -o build/DoublyLinkedList.o
	ar rcs build/libDoublyLinkedList.a build/DoublyLinkedList.o
	rm build/DoublyLinkedList.o
	gcc -fPIC -c src/DoublyLinkedList.c -Iincludes -o build/DoublyLinkedList.o
	gcc -shared build/DoublyLinkedList.o -o build/libDoublyLinkedList.so
	rm build/DoublyLinkedList.o

clean:
	rm -r build bin

