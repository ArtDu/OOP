CC = g++
FLAGS = -std=c++11
SOURCES = main.o TStack.o TStackItem.o Trapeze.o Rhombus.o Pentagon.o
EXECUTABLE = main
all: build

build: main.o TStack.o TStackItem.o Trapeze.o Rhombus.o Pentagon.o
	$(CC) $(FLAGS) -o $(EXECUTABLE) $(SOURCES)

main.o: main.cpp TStack.h TStackItem.h Trapeze.h Rhombus.h Pentagon.h
	$(CC) $(FLAGS) -c main.cpp


TStack.o: TStack.cpp TStack.h
	$(CC) $(FLAGS) -c TStack.cpp

TStackItem.o: TStackItem.cpp TStackItem.h
	$(CC) $(FLAGS) -c TStackItem.cpp

Trapeze.o: Trapeze.cpp Trapeze.h
	$(CC) $(FLAGS) -c Trapeze.cpp

Rhombus.o: Rhombus.cpp Rhombus.h
	$(CC) $(FLAGS) -c Rhombus.cpp

Pentagon.o: Pentagon.cpp Pentagon.h
	$(CC) $(FLAGS) -c Pentagon.cpp

clean:
	rm -f $(SOURCES)
