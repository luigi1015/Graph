#ifndef Node_h
#define Node_h

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

#endif /* Node_h */
