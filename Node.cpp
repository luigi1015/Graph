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
			Node( Key newKey, Value newValue, int newN );//Constructor with values.
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

	template<typename Key, typename Value> Node<Key, Value>::Node( Key newKey, Value newValue, int newN )
	{//Constructor with values.
	}

	int Node::size() const
	{//Return the size.
	}

	template <typename Key, typename Value> Value Node::get( Key getKey )
	{
	}

	template <typename Key, typename Value> void put( Key newKey, Value newValue )
	{
	}
}
