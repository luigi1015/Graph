#include <vector>
#include "Link.h"

/*

namespace Graph
{
	class Link
	{//A single node of a graph.
		private:
			int weight;
			int startNodeID, endNodeID;

		public:
			Link( int newWeight, int newStartID, int newEndID);//Initializes the Node ids and weight.
			void setWeight( int newWeight );//Set the Weight.
			int getWeight();//Return the weight.
			void setStartNode( int newStartID );//Set the starting node ID.
			int getStartNode();//Return the starting node ID.
			void setEndNode( int newEndID );//Set the ending node ID.
			int getEndNode();//Return the ending node ID.
	};
}
*/

namespace Graph
{
	Link::Link( int newWeight, int newStartID, int newEndID )
	{//Initializes the Node ids and weight.
	}
	
	void Link::setWeight( int newWeight )
	{//Set the Weight.
		weight = newWeight;
	}
	
	int Link::getWeight()
	{//Return the weight.
		return weight;
	}
	
	void Link::setStartNode( int newStartID )
	{//Set the starting node ID.
		startNodeID = newStartID;
	}
	
	int Link::getStartNode()
	{//Return the starting node ID.
		return startNodeID;
	}
	
	void Link::setEndNode( int newEndID )
	{//Set the ending node ID.
		endNodeID = newEndID;
	}
	int Link::getEndNode()
	{//Return the ending node ID.
		return endNodeID;
	}
}
