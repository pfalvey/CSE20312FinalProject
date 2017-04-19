CC=g++
CFLAGS=-std=c++14 -Wall

EXEC=map

all: $(EXEC)


$(EXEC): main.cpp Graph.o
	$(CC) $(CFLAGS) -o $@ -c main.cpp Graph.o

Graph.o: Graph.cpp Graph.h
	$(CC) $(CFLAGS) -o $@ -c $<


clean:
	rm *.o
	rm $(EXEC)



