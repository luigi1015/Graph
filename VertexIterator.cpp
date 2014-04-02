//#include <vector>
#include <map>
#include <sstream>
#include "Vertex.cpp"
#include "Edge.h"

namespace Graph
{
	template <class T> class VertexIterator
	{//A class to iterate through the vertices of a graph.
		private:
			Graph<T> graph;

		public:
			VertexIterator( Graph<T>& newGraph );//Initialize the iterator with a graph.
			~VertexIterator();
			void first();
			void next();
			bool isDone() const;
			Vertex<T> currentItem() const;
	};
/*
	template <class T> VertexIterator<T>::VertexIterator( Graph<T>& newGraph )
	{//Initialize the iterator with a graph;
	}
*/
