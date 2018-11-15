CC = g++
FLAGS = -std=c++11
SOURCES = main.o TStack.o TStackItem.o Trapeze.o
EXECUTABLE = main
all: build

build: main.o TStack.o TStackItem.o Trapeze.o
	$(CC) $(FLAGS) -o $(EXECUTABLE) $(SOURCES)

main.o: main.cpp TStack.h TStackItem.h Trapeze.h
	$(CC) $(FLAGS) -c main.cpp


TStack.o: TStack.cpp TStack.h
	$(CC) $(FLAGS) -c TStack.cpp

TStackItem.o: TStackItem.cpp TStackItem.h
	$(CC) $(FLAGS) -c TStackItem.cpp

Trapeze.o: Trapeze.cpp Trapeze.h
	$(CC) $(FLAGS) -c Trapeze.cpp


clean:
	rm -f *.o
