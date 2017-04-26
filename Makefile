CC=g++
CFLAGS=-std=c++14 -Wall
LD=g++
LDFLAGS= -L.
EXEC=map
FUNCS=Graph. astar.

all: $(EXEC)


$(EXEC): main.cpp $(FUNCS:.=.o)
	@echo Linking $@...
	$(LD) $(LDFLAGS) main.cpp $(FUNCS:.=.o) -o $@

%.o: %.cpp Graph.h
	@echo Compiling $@...
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm *.o
	rm $(EXEC)



