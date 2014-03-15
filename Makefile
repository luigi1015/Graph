.PHONY: all test clean

all: Vertex.o Edge.o Graph.o BreadthFirstSearch.o

test: EdgeTest

Vertex.o: Vertex.cpp
	g++ -g -Wall -c Vertex.cpp

Edge.o: Edge.h Edge.cpp
	g++ -g -Wall -c Edge.cpp

EdgeTest: Edge.h Edge.cpp Edge.o EdgeTest.cpp
	g++ -g -Wall -o EdgeTest EdgeTest.cpp Edge.o -lcppunit

Graph.o: Graph.cpp
	g++ -g -Wall -c Graph.cpp

BreadthFirstSearch.o: BreadthFirstSearch.cpp
	g++ -g -Wall -c BreadthFirstSearch.cpp

TestApp: test.cpp Vertex.o Edge.o BreadthFirstSearch.o
	g++ -g -Wall -o Test test.cpp Vertex.o Edge.o BreadthFirstSearch.o

clean:
	rm *.o *~ *.gch Test EdgeTest
