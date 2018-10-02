CC = g++
FLAGS = -std=c++11
SOURCES = main.o Pentagon.o Rhombus.o Trapeze.o
EXECUTABLE = main
all: build

build: main.o Pentagon.o Rhombus.o Trapeze.o
	$(CC) $(FLAGS) -o $(EXECUTABLE) $(SOURCES)

main.o: main.cpp Pentagon.h Rhombus.h Trapeze.h
	$(CC) $(FLAGS) -c main.cpp


Pentagon.o: Pentagon.cpp Pentagon.h
	$(CC) $(FLAGS) -c Pentagon.cpp

Rhombus.o: Rhombus.cpp Rhombus.h
	$(CC) $(FLAGS) -c Rhombus.cpp

Trapeze.o: Trapeze.cpp Trapeze.h
	$(CC) $(FLAGS) -c Trapeze.cpp


clean:
	rm -f $(SOURCES)
