#ifndef Link_h
#define Link_h

#include <vector>
//#include "Node.h"

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

#endif /* Link_h */
