CC = g++
FLAGS = -std=c++11
SOURCES = main.o TStack.o TStackSnd.o TAllocationBlock.o TStackItem.o TStackItemSnd.o Trapeze.o Rhombus.o Pentagon.o
EXECUTABLE = main
all: build

build: main.o TStack.o TStackSnd.o TAllocationBlock.o TStackItem.o TStackItemSnd.o Trapeze.o Rhombus.o Pentagon.o
	$(CC) $(FLAGS) -o $(EXECUTABLE) $(SOURCES)

main.o: main.cpp stack/TStack.h stack/TStackSnd.h stack/TAllocationBlock.h stack/TStackItem.h stack/TStackItemSnd.h figure/Trapeze.h figure/Rhombus.h figure/Pentagon.h
	$(CC) $(FLAGS) -c main.cpp

TStack.o: stack/TStack.cpp stack/TStack.h
	$(CC) $(FLAGS) -c stack/TStack.cpp

TStackSnd.o: stack/TStackSnd.cpp stack/TStackSnd.h
	$(CC) $(FLAGS) -c stack/TStackSnd.cpp

TAllocationBlock.o: stack/TAllocationBlock.cpp stack/TAllocationBlock.h
	$(CC) $(FLAGS) -c stack/TAllocationBlock.cpp

TStackItem.o: stack/TStackItem.cpp stack/TStackItem.h
	$(CC) $(FLAGS) -c stack/TStackItem.cpp

TStackItemSnd.o: stack/TStackItemSnd.cpp stack/TStackItemSnd.h
	$(CC) $(FLAGS) -c stack/TStackItemSnd.cpp

Trapeze.o: figure/Trapeze.cpp figure/Trapeze.h
	$(CC) $(FLAGS) -c figure/Trapeze.cpp

Rhombus.o: figure/Rhombus.cpp figure/Rhombus.h
	$(CC) $(FLAGS) -c figure/Rhombus.cpp

Pentagon.o: figure/Pentagon.cpp figure/Pentagon.h
	$(CC) $(FLAGS) -c figure/Pentagon.cpp
	
clean:
	rm -f *.o
