all: Vertex.o Edge.o BreadthFirstSearch.o Test

Vertex.o: Vertex.cpp
	g++ -g -Wall -c Vertex.cpp

Edge.o: Edge.h Edge.cpp
	g++ -g -Wall -c Edge.cpp

BreadthFirstSearch.o: BreadthFirstSearch.cpp
	g++ -g -Wall -c BreadthFirstSearch.cpp

Test: test.cpp Vertex.o Edge.o BreadthFirstSearch.o
	g++ -g -Wall -o Test test.cpp Vertex.o Edge.o BreadthFirstSearch.o

clean:
	rm *.o *~ *.gch
