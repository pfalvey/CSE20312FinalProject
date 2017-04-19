CC=g++
BOOST=/usr/local/boost_1_63_0
FLAGS=-Wall -I $(BOOST)

EXEC=main
LIB=Graph

all: $(EXEC)

graph:
	$(CC) $(FLAGS) graph_sample.cpp

$(LIB).o: $(LIB).cpp $(LIB).h
	$(CC) -c $(FLAGS) $(LIB).cpp -o $(LIB).o

$(EXEC): driver.cpp $(LIB).o
	$(CC) $(FLAGS) driver.cpp $(LIB).o -o $(EXEC) 
