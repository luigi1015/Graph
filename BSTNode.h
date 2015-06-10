#ifndef BSTNode_h
#define BSTNode_h

#include <vector>
#include <ostream>

namespace Graph
{
	template <typename Key, typename Value> class BSTNode
	{//A single edge of a graph.
		private:
			Key key;
			Value value;
			BSTNode left, right;
			int N;

		public:
			BSTNode();
			int size() const;//Return the size.
			Value get( Key getKey );
			void put( Key newKey, Value newValue );
	};
}

#endif /* BSTNode_h */
