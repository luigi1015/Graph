#include <vector>
#include <ostream>
#include "Edge.h"

/*

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
			int getWeight();//Return the weight.
			void setStartVertex( int newStartID );//Set the starting vertex ID.
			int getStartVertex();//Return the starting vertex ID.
			void setEndVertex( int newEndID );//Set the ending vertex ID.
			int getEndVertex();//Return the ending vertex ID.
			template <class Y> friend std::ostream& operator<<(std::ostream &out, const Edge<Y> &e);//For stream output.
	};
}
*/

namespace Graph
{
	Edge::Edge( int newWeight, int newStartID, int newEndID )
	{//Initializes the vertex ids and weight.
		setWeight( newWeight );
		setStartVertex( newStartID );
		setEndVertex( newEndID );
	}
	
	void Edge::setWeight( int newWeight )
	{//Set the Weight.
		weight = newWeight;
	}
	
	int Edge::getWeight() const
	{//Return the weight.
		return weight;
	}
	
	void Edge::setStartVertex( int newStartID )
	{//Set the starting vertex ID.
		startVertexID = newStartID;
	}
	
	int Edge::getStartVertex() const
	{//Return the starting vertex ID.
		return startVertexID;
	}
	
	void Edge::setEndVertex( int newEndID )
	{//Set the ending vertex ID.
		endVertexID = newEndID;
	}
	
	int Edge::getEndVertex() const
	{//Return the ending vertex ID.
		return endVertexID;
	}

std::ostream& operator<<(std::ostream& out, const Graph::Edge& e)
{//For stream output.
	return out << "Weight: " << e.getWeight() << " from vertex " << e.getStartVertex() << " to vertex " << e.getEndVertex() << " ";
}
}
