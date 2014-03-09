all: Node.o Link.o

Node.o: Node.h Node.cpp
	g++ -g -Wall -c Node.cpp

Link.o: Link.h Link.cpp
	g++ -g -Wall -c Link.cpp

clean:
	rm *.o *~ *.gch
