#include <vector>
#include <ostream>
#include "Vertex.h"

/*
namespace Graph
{
	template <class T> class Vertex
	{//A single vertex of a graph.
		private:
			std::vector<Edge> edges;
			int ID;
			T value;

		public:
			Vertex( int newID, T newValue );//Initializes the id, value and edges.
			void addEdge( Edge newEdge );//Add an edge to the list.
			void clearEdges();//Clears all the Edges.
			size_t getNumEdges();//Return the number of edges in the list.
			Edge getEdge( size_t n );//Get the edge at index n. The range for n is from 0 to getNumEdges(), inclusive.
			void setID( int newID );//Sets the ID to the new value.
			int getID();//Returns the ID;
			void setValue( T newValue );//Sets the value to the new one.
			T getValue();//Returns the value.
			template <class Y> friend std::ostream& operator<<(std::ostream &out, const Vertex<Y> &v);//For stream output.
	};
}
*/

namespace Graph
{
	template <class T> Vertex<T>::Vertex( int newID, T newValue )
	{//Initializes the id and value.
		ID = newID;
		value = newValue;
	}
	
	template <class T> void Vertex<T>::addEdge( Edge newEdge )
	{//Add a edge to the list.
		edges.push_back( newEdge );
	}
	
	template <class T> void Vertex<T>::clearEdges()
	{//Clears all the edges.
		edges.clear();
	}
	
	template <class T> size_t Vertex<T>::getNumEdges() const
	{//Return the number of edges in the list.
		return edges.size();
	}
	
	template <class T> Edge Vertex<T>::getEdge( size_t n ) const
	{//Get the edge at index n. The range for n is from 0 to getNumEdges(), inclusive.
		return edges.at( n );
	}
	
	template <class T> void Vertex<T>::setID( int newID )
	{//Sets the ID to the new value.
		ID = newID;
	}
	
	template <class T> int Vertex<T>::getID() const
	{//Returns the ID;
		return ID;
	}
	
	template <class T> void Vertex<T>::setValue( T newValue )
	{//Sets the value to the new one.
		value = newValue;
	}
	
	template <class T> T Vertex<T>::getValue() const
	{//Returns the value.
		return value;
	}
}

template <class Y> std::ostream& operator<<(std::ostream &out, const Graph::Vertex<Y> &v)
{//For stream output.
	out << "Vertex " << v.getID() << "\n";
	
	for( int i = 0; i < v.getNumEdges(); i++ )
	{
		out << (i+1) << ". " << v.getEdge( i ) << "\n";
	}
	
	return out;
}
