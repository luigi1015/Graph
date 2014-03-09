#ifndef Vertex_h
#define Vertex_h

#include <vector>
#include <ostream>
#include "Edge.h"

namespace Graph
{
	template <class T> class Vertex
	{//A single vertex of a graph.
		private:
			std::vector<Edge> edges;
			int ID;
			T value;

		public:
			Vertex( int newID, T newValue );//Initializes the id and value.
			void addEdge( Edge newEdge );//Add an edge to the list.
			void clearEdges();//Clears all the edges.
			size_t getNumEdges() const;//Return the number of edges in the list.
			Edge getEdge( size_t n ) const;//Get the edge at index n. The range for n is from 0 to getNumEdges(), inclusive.
			void setID( int newID );//Sets the ID to the new value.
			int getID() const;//Returns the ID;
			void setValue( T newValue );//Sets the value to the new one.
			T getValue() const;//Returns the value.
			template <class Y> friend std::ostream& operator<<(std::ostream &out, const Vertex<Y> &v);//For stream output.
	};
}

#endif /* Vertex_h */
