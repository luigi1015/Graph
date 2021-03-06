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
			Value get( Node subtreeNode, Key getKey );//Returns the value of the node with a specified key that is within the subtree rooted at subtreeNode. Returns null if the node isn't found.
			Node put( Node rootNode, Key newKey, Value newValue );
			Node min( Node minNode );
			Key floor( Node rootNode, Key key );//Returns the largest Key less than or equal to key in the tree rooted at rootNode.
			Key select( int n );

		public:
			int size() const;//Returns the size of the tree.
			int size(Node node) const;//Returns the size at node node.
			Value get( Key getKey );//Returns the value of the node with a specified key.
			void put( Key newKey, Value newValue );//Puts the specified node in the tree.
			Key min();
			Key floor( Key key );//Returns the largest Key less than or equal to key.
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
	{//Search for the key. If there is a node with the key, update the value. If not, add it to the tree.
		root = put(root, newKey, newValue);
	}

	template <typename Key, typename Value> Node BST<Key, Value>::put( Node rootNode, Key newKey, Value newValue )
	{//If a node with newKey exists in the tree rooted at rootNode, change the value of the node. If not, add it to the tree.
		if( newKey == null )
		{
			return new Node( newKey, newValue, 1 );
		}

		int compare = newKey.compareTo( rootNode.key );
		if( compare < 0 )
		{
			rootNode.left = put( rootNode.left, newKey, newValue );
		}
		else if( compare > 0 )
		{
			rootNode.right = put( rootNode.right, newKey, newValue );
		}
		else
		{
			rootNode.value = newValue;
		}

		rootNode.N = size(rootNode.left) + size(rootNode.right) + 1;

		return rootNode;
	}

	template <typename Key, typename Value> Key BST<Key, Value>::min()
	{
		return min(root).key;
	}

	template <typename Key, typename Value> void BST<Key, Value>::min( Node rootNode )
	{
		if( rootNode.left == null )
		{
			return rootNode;
		}
		else
		{
			return min( rootNode.left );
		}
	}

	template <typename Key, typename Value> Key BST<Key, Value>::floor( Node rootNode, Key key )
	{
		if( rootNode == null )
		{
			return null;
		}
		int compare = key.compareTo( rootNode.key );
		if( compare == 0 )
		{
			return rootNode;
		}
		else if( compare < 0 )
		{
			return floor( rootNode.left, key );
		}
		
		Node t = floor( rootNode.right, key );
		if( t != null )
		{
			return t;
		}
		else
		{
			return rootNode;
		}
	}

	template <typename Key, typename Value> BST<Key, Value>::Key floor( Key key )
	{
		Node rootNode = floor( root, key );
		if( rootNode == null )
		{
			return null;
		}
		else
		{
			return rootNode.key;
		}
	}

	template <typename Key, typename Value> BST<Key, Value>::Key select( int n )
	{
		return select( root, n ).key;
	}

	template <typename Key, typename Value> BST<Key, Value>::Key select( Node rootNode, int n )
	{
		if( n == null )
		{
			return 0;
		}
		int t = size( x.left );
		if( t > n )
		{
			return select( x.left, n );
		}
		else if (t < n )
		{
			return select( x.right, n-t-1 );
		}
	}
}
