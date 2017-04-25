CC=g++
CFLAGS=-std=c++14 -Wall
LD=g++
LDFLAGS= -L.
EXEC=map
FUNCS=Graph. astar.

all: $(EXEC)


$(EXEC): main.cpp $(FUNCS:.=.o)
	$(LD) $(LDFLAGS) main.cpp $(FUNCS:.=.o) -o $@

%.o: %.cpp Graph.h
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm *.o
	rm $(EXEC)



