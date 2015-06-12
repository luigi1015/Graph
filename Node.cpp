/*
#include <vector>
#include <ostream>

namespace Graph
{
	template <class Key, Value> class Node
	{//A single edge of a graph.
		private:
			Key key;
			Value value;
			Node left, right;
			int N;

		public:
			int size() const;//Return the size.
			Value get( Key getKey );
			void put( Key newKey, Value newValue );
	};
}
*/
#include "Node.h"

namespace Graph
{
	template<typename Key, typename Value> Node<Key, Value>::Node()
	{
	}

	int Node::size() const
	{//Return the size.
	}

	template <typename Key, typename Value> Value Node<Key, Value>::get( Key getKey )
	{//Returns the node with a specified key.
	}

	template <typename Key, typename Value> void put( Key newKey, Value newValue )
	{//Create a node in the tree with thespecified key and value.
	}
}
