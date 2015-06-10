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
	template<typename Key, typename Value> BSTNode<Key, Value>::BSTNode()
	{//COnstructor
	}

	int BSTNode::size() const
	{//Return the size.
	}

	template <typename Key, typename Value> Value BSTNode<Key, Value>::get( Key getKey )
	{//Return the value of the node with a given key.
	}

	template <typename Key, typename Value> void put( Key newKey, Value newValue )
	{//Create a node in the tree with thespecified key and value.
	}
}
