#include "Vertex.cpp"
#include "Edge.h"
#include <vector>
#include <queue>
#include <iostream>

enum BFSColors { BFSWhite, BFSGray, BFSBlack };

struct BreadthFirstTreeInfo
{
	long distance;//The distance (the minimum number of edges) from this vertex to the source vertex. -1 means infinite distance (in other words, disconnected from the tree).
	long predecessor;//The predecessor of the vertex. -1 means there is no predecessor.
};

template <class T> std::vector< Graph::Vertex<BreadthFirstTreeInfo> > breadthFirstSearch( std::vector< Graph::Vertex<T> > graph, size_t sourceVertexIndex )
{//Does a breadth first search on graph starting at the vertex at index sourceVertexIndex of the vector. Returns the breadth-first tree. **Assumes the link IDs  in graph are the same as the Vector indices.**
	std::vector<BFSColors> colors;//White, Gray or Black colors. White vertices have not been discovered. Gray vertices have been discovered but may have undiscovered adjacent vertices. Black vertices and all their adjacent vertices have been discovered.
	std::vector<long> distances;//The distances (the minimum number of edges) from each vertex to the source vertex. -1 means infinite distance (in other words, disconnected from the tree).
	std::vector<long> predecessors;//The predecessors of each vertex. -1 means there is no predecessor.
	std::vector< Graph::Vertex<BreadthFirstTreeInfo> > breadthFirstTree;
	std::queue< Graph::Vertex<T> > grayList;

	std::cout << "Test 0" << std::endl;

	for( int i = 0; i < graph.size(); i++ )
	{
		if( i == sourceVertexIndex )
		{
			colors.push_back( BFSGray );
			distances.push_back( 0 );
			predecessors.push_back( -1 );
			
			//Create the source vertex for the breadth first tree.
			BreadthFirstTreeInfo sourceInfo;
			sourceInfo.distance = 0;
			sourceInfo.predecessor = -1;
			Graph::Vertex<BreadthFirstTreeInfo> sourceVertex( i, sourceInfo );
			breadthFirstTree.push_back( sourceVertex );
		}
		else
		{
			colors.push_back( BFSWhite );
			distances.push_back( -1 );
			predecessors.push_back( -1 );
			
			//Create the vertex for the breadth first tree.
			BreadthFirstTreeInfo sourceInfo;
			sourceInfo.distance = -1;
			sourceInfo.predecessor = -1;
			Graph::Vertex<BreadthFirstTreeInfo> sourceVertex( i, sourceInfo );
			breadthFirstTree.push_back( sourceVertex );
		}
	}

	std::cout << "Test 1" << std::endl;

	grayList.push( graph.at(sourceVertexIndex) );

	std::cout << "Test 2" << std::endl;

	while( !(grayList.empty()) )
	{
		Graph::Vertex<T> newVertex = grayList.front();
		grayList.pop();

	std::cout << "Test 3" << std::endl;
	std::cout << "ID: " << newVertex.getID() << " Num Edges: " << newVertex.getNumEdges() << std::endl;


		for( int i = 0; i < newVertex.getNumEdges(); i++ )
		{
	std::cout << "Test 4, i=" << i << " End Vertex = " << newVertex.getEdge(i).getEndVertex() << std::endl;

			if( colors.at(newVertex.getEdge(i).getEndVertex()) == BFSWhite )
			{
	std::cout << "Test 5" << std::endl;

				colors.at(newVertex.getEdge(i).getEndVertex()) = BFSGray;
				distances.at(newVertex.getEdge(i).getEndVertex()) = distances.at(newVertex.getID()) + 1;
				predecessors.at(newVertex.getEdge(i).getEndVertex()) = newVertex.getID();
				grayList.push( graph.at(newVertex.getEdge(i).getEndVertex()) );

	std::cout << "Test 6" << std::endl;

				BreadthFirstTreeInfo newBFSInfo;
				newBFSInfo.distance = distances.at(newVertex.getEdge(i).getEndVertex());
				newBFSInfo.predecessor = predecessors.at(newVertex.getEdge(i).getEndVertex());
				breadthFirstTree.at(newVertex.getEdge(i).getEndVertex()).setValue( newBFSInfo );
				//breadthFirstTree.at(newVertex.getEdge(i).getEndVertex()).getValue().distance = distances.at(newVertex.getEdge(i).getEndVertex());
				//breadthFirstTree.at(newVertex.getEdge(i).getEndVertex()).getValue().predecessor = predecessors.at(newVertex.getEdge(i).getEndVertex());
				Graph::Edge newEdge( 1, newVertex.getID(), newVertex.getEdge(i).getEndVertex() );
				breadthFirstTree.at(newVertex.getEdge(i).getEndVertex()).addEdge( newEdge );
			}
		}

	std::cout << "Test 7" << std::endl;

		
		colors.at( newVertex.getID() ) = BFSBlack;
	}
	
	return breadthFirstTree;
}
