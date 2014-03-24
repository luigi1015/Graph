.PHONY: all test clean

all: Vertex.o Edge.o Graph.o BreadthFirstSearch.o test

test: VertexTest EdgeTest GraphTest

Vertex.o: Vertex.cpp
	g++ -g -Wall -c Vertex.cpp

VertexTest: Vertex.cpp Vertex.o VertexTest.cpp Edge.o
	g++ -g -Wall -o VertexTest VertexTest.cpp Edge.o Vertex.o -lcppunit

Edge.o: Edge.h Edge.cpp
	g++ -g -Wall -c Edge.cpp

EdgeTest: Edge.h Edge.cpp Edge.o EdgeTest.cpp
	g++ -g -Wall -o EdgeTest EdgeTest.cpp Edge.o -lcppunit

Graph.o: Graph.cpp
	g++ -g -Wall -c Graph.cpp

GraphTest: Graph.cpp Graph.o Vertex.o GraphTest.cpp Edge.o
	g++ -g -Wall -o GraphTest GraphTest.cpp Graph.o Edge.o Vertex.o -lcppunit

BreadthFirstSearch.o: BreadthFirstSearch.cpp
	g++ -g -Wall -c BreadthFirstSearch.cpp

TestApp: test.cpp Vertex.o Edge.o BreadthFirstSearch.o
	g++ -g -Wall -o Test test.cpp Vertex.o Edge.o BreadthFirstSearch.o

clean:
	rm *.o *~ *.gch Test EdgeTest GraphTest VertexTest
