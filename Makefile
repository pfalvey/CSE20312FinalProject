CC=g++
CFLAGS=-std=c++14 -Wall
LD=g++
LDFLAGS= -L.
EXEC=map
FUNCS=Graph. astar. loadGraph. tvsida_star.

all: $(EXEC)


$(EXEC): main.cpp $(FUNCS:.=.o)
	@echo Linking $@...
	@$(LD) $(LDFLAGS) main.cpp $(FUNCS:.=.o) -o $@

%.o: %.cpp Graph.h
	@echo Compiling $@...
	@$(CC) $(CFLAGS) -c $< -o $@


clean:
	@echo Cleaning...
	@rm -f *.o
	@rm -f $(EXEC)
