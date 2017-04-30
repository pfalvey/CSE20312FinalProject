CC=g++
CFLAGS=-std=c++14 -Wall
LD=g++
LDFLAGS= -L.
EXEC=map
FUNCS=Graph. astar. loadGraph. estar.

all: $(EXEC)


$(EXEC): main.cpp $(FUNCS:.=.o)
	@echo Linking $@...
	$(LD) $(LDFLAGS) main.cpp $(FUNCS:.=.o) -o $@

%.o: %.cpp Graph.h
	@echo Compiling $@...
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f *.o
	rm -f $(EXEC)
