#ifndef BST_h
#define BST_h

#include <vector>
#include <ostream>
#include "Node.h"

namespace Graph
{
	template <typename Key, typename Value> class BST
	{//A Binary Search Tree.
		private:
			Node<Key, Value> root;
			Value get( Node subtreeNode, Key getKey );//Returns the value of the node with a specified key that is within the subtree rooted at subtreeNode. Returns null if the node isn't found.
			Node put( Node rootNode, Key newKey, Value newValue );
			Node min( Node minNode );
			Key floor( Node rootNode, Key key );
			Key select( Node rootNode, int n );

		public:
			int size() const;//Returns the size of the tree.
			int size(Node node) const;//Returns the size at node node.
			Value get( Key getKey );//Returns the value of the node with a specified key.
			void put( Key newKey, Value newValue );//Puts the specified node in the tree.
			Key min();
			Key floor( Key key );//Returns the largest Key less than or equal to key.
			Key select( int n );//Returns the key at n.
	};
}

#endif /* BST_h */
