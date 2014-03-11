all: Vertex.o Edge.o

Vertex.o: Vertex.cpp
	g++ -g -Wall -c Vertex.cpp

Edge.o: Edge.h Edge.cpp
	g++ -g -Wall -c Edge.cpp

clean:
	rm *.o *~ *.gch
