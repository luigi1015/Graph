#include <vector>
#include <ostream>
#include "BST.h"
/*
namespace Graph
{
	template <typename Key, typename Value> class BST
	{//A Binary Search Tree.
		private:
			Node<Key, Value> root;

		public:
			int size() const;//Return the size of the tree.
			int size(Node node) const;//Return the size at node node.
			Value get( Key getKey );
			void put( Key newKey, Value newValue );
	};
}
*/

namespace Graph
{
	template <typename Key, typename Value> int BST<Key, Value>::size() const
	{
		return size( root );
	}

	template <typename Key, typename Value> int size(Node node) const
	{//Return the size at node node.
		if( node == null )
		{
			return 0;
		}
		else
		{
			return node.N;
		}
	}

	template <typename Key, typename Value> Value BST<Key, Value>::get( Key getKey )
	{
	}

	template <typename Key, typename Value> void BST<Key, Value>::put( Key newKey, Value newValue )
	{
	}
}
