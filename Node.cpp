#include <vector>
#include "Node.h"

/*
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
*/

namespace Graph
{
	template <class T> Node<T>::Node( int newID, T newValue )
	{//Initializes the id, value and links.
		ID = newID;
		value = newValue;
	}
	
	template <class T> void Node<T>::addLink( Link newLink )
	{//Add a link to the list.
		links.push_back( newLink );
	}
	
	template <class T> void Node<T>::clearLinks()
	{//Clears all the links.
		links.clear();
	}
	
	template <class T> void Node<T>::setID( int newID )
	{//Sets the ID to the new value.
		ID = newID;
	}
	
	template <class T> int Node<T>::getID()
	{//Returns the ID;
		return ID;
	}
	
	template <class T> void Node<T>::setValue( T newValue )
	{//Sets the value to the new one.
		value = newValue;
	}
	
	template <class T> T Node<T>::getValue()
	{//Returns the value.
		return value;
	}
}
