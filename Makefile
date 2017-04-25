CC=g++
CFLAGS=-std=c++14 -Wall

EXEC=map

all: $(EXEC)


$(EXEC): main.cpp Graph.o astar.o
	@echo Compiling $(EXEC)...
	@$(CC) $(CFLAGS) $^ -o $@

Graph.o: Graph.cpp Graph.h
	@echo Compiling $@...
	@$(CC) $(CFLAGS) -c $< -o $@

astar.o: astar.cpp Graph.h
	@echo Compiling $@...
	@$(CC) $(CFLAGS) -c $< -o $@


clean:
	@echo Cleaning...
	@rm -f *.o
	@rm -f $(EXEC)
