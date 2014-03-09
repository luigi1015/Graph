#ifndef Node_h
#define Node_h

#include <vector>
#include "Link.h"

namespace Graph
{
	template <class T> class Node
	{//A single node of a graph.
		private:
			std::vector<Link> links;
			int ID;
			T value;

		public:
			Node( int newID, T newValue );//Initializes the id, value and links.
			void addLink( Link newLink );//Add a link to the list.
			void clearLinks();//Clears all the links.
			void setID( int newID );//Sets the ID to the new value.
			int getID();//Returns the ID;
			void setValue( T newValue );//Sets the value to the new one.
			T getValue();//Returns the value.
	};
}

#endif /* Node_h */
