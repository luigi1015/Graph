//#include <vector>
#include <map>
#include <sstream>
#include "Vertex.cpp"
#include "Edge.h"

namespace Graph
{
	template <class T> class Graph
	{//A graph of vertices. Every vertex is required to have a unique int ID.
		private:
			//std::vector< Vertex<T> > vertices;
			std::map<int, Vertex<T> > vertices;

		public:
			//Graph();//Initializes the Graph.
			void addVertex( int vertexID, T newValue );//Add a vertex.
			void addVertex( int vertexID, Vertex<T> newVertex );//Add a vertex.
			void addEdge( int vertexID, Edge newEdge );//Add an edge to a vertex.
			void clearVertices();//Clears all the vertices.
			void deleteVertex( int vertexID );//Delete a vertex.
			size_t getNumVertices() const;//Return the number of vertices in the graph.
			Vertex<T> getVertex( int vertexID );//Get the vertex of ID vertexID.
			std::vector<int> getVertexIDs() const;//Returns all vertex IDs.
			void changeVertexID( int oldVertexID, int newVertexID );//Change a vertex's ID.
	};
/*
	template <class T> Graph<T>::Graph()
	{
	}
*/

	template <class T> void Graph<T>::addVertex( int newVertexID, T newValue )
	{//Add a vertex. Throws an exception if vertexID is already in use in the graph.
		Vertex<T> newVertex( newVertexID, newValue );
		if( (vertices.insert( std::pair< int, Vertex<T> >(newVertexID, newVertex) )).second ==  false )
		{//The insert method returns a std::pair object, the second value of which is a bool that is false if there's already an element with that key. Check that bool and throw an error if it's false.
			std::ostringstream errorStream;
			errorStream << "Vertex already exists at ID " << newVertexID;
			throw errorStream.str().c_str();
		}
	}

	template <class T> void Graph<T>::addVertex( int newVertexID, Vertex<T> newVertex )
	{//Add a vertex. Throws an exception if vertexID is already in use in the graph.
		if( (vertices.insert( std::pair< int, Vertex<T> >(newVertexID, newVertex) )).second ==  false )
		{//The insert method returns a std::pair object, the second value of which is a bool that is false if there's already an element with that key. Check that bool and throw an error if it's false.
			std::ostringstream errorStream;
			errorStream << "Vertex already exists at ID " << newVertexID;
			throw errorStream.str().c_str();
		}
	}

	template <class T> void Graph<T>::addEdge( int vertexID, Edge newEdge )
	{//Add an edge to a vertex.
		getVertex(vertexID).addEdge( newEdge );
	}

	template <class T> void Graph<T>::clearVertices()
	{//Clears all the vertices.
		vertices.clear();
	}

	template <class T> void Graph<T>::deleteVertex( int vertexID )
	{//Delete a vertex.
		vertices.erase( vertexID );
	}

	template <class T> size_t Graph<T>::getNumVertices() const
	{//Return the number of vertices in the graph.
		return vertices.size();
	}

	template <class T> Vertex<T> Graph<T>::getVertex( int vertexID )
	{//Get the vertex of ID vertexID.
		return vertices.at( vertexID );
	}

	template <class T> std::vector<int> Graph<T>::getVertexIDs() const
	{//Returns all vertex IDs.
		std::vector<int> IDs;
		//std::map< int, Vertex<T> >::iterator it;

		for( typename std::map<int, Vertex<T> >::iterator it = vertices.begin(); it != vertices.end(); it++ )
		{//Go through each element and save the key.
			IDs.push_back( it->first );
		}

		return IDs;
	}

	template <class T> void Graph<T>::changeVertexID( int oldVertexID, int newVertexID )
	{//Change a vertex's ID.
		Vertex<T> changedVertex = getVertex( oldVertexID );
		vertices.erase( oldVertexID );
		
		changedVertex.setID( newVertexID );
		addVertex( newVertexID, changedVertex );
		//vertices.insert( std::pair< int, Vertex<T> >(newVertexID, changedVertex) );
	}
}
