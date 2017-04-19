CC=g++
CFLAGS=-std=c++14 -Wall

EXEC=map

all: $(EXEC)


$(EXEC): main.cpp Graph.o
	$(CC) $(CFLAGS) main.cpp Graph.o -o $@

Graph.o: Graph.cpp Graph.h
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm *.o
	rm $(EXEC)



