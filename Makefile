CC = clang++
DEBUG = -g

CFLAGS = -std=c++1y -c -g -O0 -Wall -Wextra -pedantic
LFLAGS = -std=c++1y -lc++abi

EXE = main
OBJS = main.o Graph.o Traversal.o Vertex.o PageRank.o
TEST_OBJS = test.o Graph.o Traversal.o Vertex.o PageRank.o catchmain.o

main : $(OBJS)
	$(CC) $(OBJS) -o main

tests : $(TEST_OBJS)
	$(CC) $(TEST_OBJS) -o tests

main.o: main.cpp include/Edge.h
	$(CC) $(CFLAGS) main.cpp

Vertex.o: src/Vertex.cpp include/Edge.h
	$(CC) $(CFLAGS) src/Vertex.cpp

Graph.o: src/Graph.cpp
	$(CC) $(CFLAGS) src/Graph.cpp

PageRank.o: src/PageRank.cpp
	$(CC) $(CFLAGS) src/PageRank.cpp

Traversal.o: src/Traversal.cpp
	$(CC) $(CFLAGS) src/Traversal.cpp

test.o: test/test.cpp include/Vertex.h include/Edge.h
	$(CC) $(CFLAGS) test/test.cpp

catchmain.o: catch/catchmain.cpp
	$(CC) $(CFLAGS) catch/catchmain.cpp

all: $(EXE)

clean:
	\rm *.o main tests

tidy: clean