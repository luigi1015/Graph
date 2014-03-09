#ifndef Edge_h
#define Edge_h

#include <vector>
#include <ostream>
//#include "Vertex.h"

namespace Graph
{
	class Edge
	{//A single edge of a graph.
		private:
			int weight;
			int startVertexID, endVertexID;

		public:
			Edge( int newWeight, int newStartID, int newEndID);//Initializes the vertex ids and weight.
			void setWeight( int newWeight );//Set the Weight.
			int getWeight() const;//Return the weight.
			void setStartVertex( int newStartID );//Set the starting vertex ID.
			int getStartVertex() const;//Return the starting vertex ID.
			void setEndVertex( int newEndID );//Set the ending vertex ID.
			int getEndVertex() const;//Return the ending vertex ID.
			friend std::ostream& operator<<(std::ostream &out, const Edge &e);//For stream output.
	};
}

#endif /* Edge_h */
