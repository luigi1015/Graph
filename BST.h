#ifndef BST_h
#define BST_h

#include <vector>
#include <ostream>
#include "Node.h"

namespace Graph
{
	template <class Key, class Value> class BST
	{//A Binary Search Tree.
		private:
			Node root;

		public:
			int size() const;//Return the size.
			Value get( Key getKey );
			void put( Key newKey, Value newValue );
	};
}

#endif /* BST_h */
