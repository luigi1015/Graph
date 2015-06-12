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
	{//Returns the size of the tree.
		return size( root );
	}

	template <typename Key, typename Value> int size(Node node) const
	{//Returns the size at node node.
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
	{//Returns the value of the node with a specified key.
		return get( root, key );
	}

	template <typename Key, typename Value> Value Node<Key, Value>::get( Node subtreeNode, Key getKey )
	{//Returns the value of the node with a specified key that is within the subtree rooted at subtreeNode. Returns null if the node isn't found.
		if( subtreeNode == null )
		{
			return null;
		}
		
		int compare = getKey.compareTo( subtreeNode.key );
		if( compare < 0 )
		{
			return get( subtreeNode.left, getKey );
		}
		else if( compare > 0 )
		{
			return get( subtreeNode.right, getKey );
		}
		else
		{
			return subtreeNode.value;
		}
	}

	template <typename Key, typename Value> void BST<Key, Value>::put( Key newKey, Value newValue )
	{
	}
}
